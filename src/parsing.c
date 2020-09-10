/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:34:25 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/10 16:31:20 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	ft_isint(const char *str, t_bool strict)
{
	unsigned int	result;
	unsigned int	border;
	int				i;
	int				sign;
	int				digits;

	result = 0;
	digits = 0;
	border = (unsigned int)(2147483647 / 10);
	i = 0;
	while (!strict && ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((result > border || (result == border && (str[i] - '0') > 7))
				&& sign == 1)
			|| ((result > border || (result == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (FALSE);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}

static int32_t	bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(bytecode[4] & 0x80);
	i = 0;
	// printf("BYTE_CODE ========== %u\n", bytecode);
	// printf("SIGN IN PARSER == %u\n",sign);
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
		{
			// printf("RESULT IN PARSER == %u\n", bytecode);
			result += bytecode[size - 1] << (i++ * 8);
		}	
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

static int32_t parse_int32(int fd)
{
	ssize_t size;
	uint8_t buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1)
		printf("ERROR READING FILE IN PARSER_INT32\n");
	if (size < 4)
		printf("ERROR INVALID CODE \n");
	return (bytecode_to_int32(buffer, 4));
}

static char		*parse_str(int fd, size_t len)
{
	ssize_t	size;
	char	*buffer;

	if (!(buffer = ft_strnew(len)))
		printf("ERR_STR_INIT");
	size = read(fd, buffer, len);
	if (size == -1)
		printf("ERR_READ_FILE");
	if (size < (ssize_t)len)
		printf("ERR_INVALID_FILE");
	return (buffer);
}

static uint8_t	*parse_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buffer;
	uint8_t	byte;

	if (!(buffer = malloc(len)))
		printf("ERR_CODE_INIT");
	size = read(fd, buffer, len);
	if (size == -1)
		printf("ERR_READ_FILE");
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		printf("ERR_INVALID_FILE");
	printf("PARSE_CODE: size %zu", len);
	for (size_t i = 0; i < len; i++)
	{
		if (i % 16 == 0)
			printf("\n");
		else if (i % 2 == 0)
			printf(" ");
		printf("%0.2x", buffer[i]);
	}
	return (buffer);
}

t_player		*parse_champion(char *filename, int id)
{
	t_player	*player;
	int			fd;

	player = init_player(id);
	if ((fd = open(filename, O_RDONLY)) < 0)
		printf("ERROR OF OPENING OF FILE\n");
	if (parse_int32(fd) != COREWAR_EXEC_MAGIC)
		printf("ERROR OF COREWAR_EXEC_MAGIC");
	player->name_plyr = parse_str(fd, PROG_NAME_LENGTH);
	if (parse_int32(fd) != 0)
		printf("ERROR OF NO NULL\n");
	if ((player->code_size = parse_int32(fd)) < 0 ||
		player->code_size > CHAMP_MAX_SIZE)
		printf("INVALID CODE SIZE\n");
	player->comment_plyr = parse_str(fd, COMMENT_LENGTH);
	if (parse_int32(fd) != 0)
		printf("NO NULL HERE\n");
	player->code = parse_code(fd, (size_t)player->code_size);
	return (player);
}

static void        add_player(t_player **list, t_player *new_player)
{
	t_player *current;

	if (list && new_player)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new_player;
		}
		else
		{
			*list = new_player;
		}
	}
}

t_bool			is_filename(const char *filename, const char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext))
		return (!ft_strcmp(ft_strchr(filename, '\0') - ft_strlen(ext), ext));
	else
		return (FALSE);
}

static void	       parse_champion_filename(int *argc, char ***argv, t_vm *vm, t_player **list)
{
	int32_t id;

	id = 0;
	if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
	{
		if (!ft_isint(*(*argv + 1), TRUE)
			|| (id = ft_atoi(*(*argv + 1))) < 1
			|| id > MAX_PLAYERS
			|| find_player(*list, id)
			|| !is_filename(*(*argv + 2), ".cor")) //argv + 2 плюс два, таким образом мы узнаем, что записано в после -n цифра или нет
			printf("HELP_WE_HAWE_TO_CALL_HERE");
		
		add_player(list, parse_champion(*(*argv + 2), id));
		vm->plyrs_nbr++;
		(*argc) -= 3;
		(*argv) += 3;
	}
	else if (is_filename(**argv, ".cor"))
	{
		add_player(list, parse_champion(**argv, id));
		vm->plyrs_nbr++;
		(*argc)--;
		(*argv)++;
	}
	else
		printf("help how to use it");
}

void	parse_dump_part(int *argc, char ***argv, t_vm *vm)
{
		if (!vm->dump_flag && *argc >= 2 && ft_isint(*(*argv + 1), TRUE))
		{
			if ((vm->dumping_nbr = ft_atoi(*(*argv + 1))) < 0)
				vm->dumping_nbr = -1;
			if (!ft_strcmp(**argv, "-d"))
				vm->dump_flag = 64;
			else
				vm->dump_flag = 32;
			(*argc) -= 2;
			(*argv) += 2;
		}
		else
			printf("how to use it");
}

void	parsing_main(int argc, char **argv, t_vm *vm)
{
	t_player *list;
	
	list = NULL; //here we have to add player переделаю как у Серёги в либе листы реализованы
	
	argc--;
	argv++;
	while (argc >= 1)
	{
		if (!ft_strcmp(*argv, "-dump") || !ft_strcmp(*argv, "-d"))
		{
			parse_dump_part(&argc, &argv, vm); //we nead investigate it
		}
		else if (!ft_strcmp(*argv, "-n") || is_filename(*argv, ".cor"))
			parse_champion_filename(&argc, &argv, vm, &list);
		else
			printf("call help help help");
	}
	printf("!!!!!!!! HERE WE HAVE TO SET THE PLYRS TO VM !!!!!!!!\n");
}
