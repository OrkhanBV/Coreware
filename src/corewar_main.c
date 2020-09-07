/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:29:55 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/08 01:30:13 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//swift book
//reywanderlikh 
//

#include "libft.h"

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

t_bool			is_filename(const char *filename, const char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext))
		return (!ft_strcmp(ft_strchr(filename, '\0') - ft_strlen(ext), ext));
	else
		return (FALSE);
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

// void	parse_dump_part(int *argc, char ***argv, t_vm *vm)
// {
// 	if (!vm->dump_flag && *argc >= 2 && ft_isint(*(*argv + 1), TRUE))
// 	{
// 		if ((vm->dumping_nbr = ft_atoi(*(*argv + 1))) < 0)
// 			vm->dumping_nbr = -1;
// 		if (!ft_strcmp(**argv, "-d"))
// 			vm->dump_flag = 64;
// 		else
// 			vm->dump_flag = 32;
// 		(*argc) -= 2;
// 		(*argv) += 2;
// 	}
// 	else
// 		printf("we need help");
// }

t_player	*find_player(t_player *list, int32_t id)
{
	t_player *player;

	player = NULL;
	if (id >= 1 && id <= 4 /*MAX_PLAYERS*/)
	{
		player = list;
		while (player)
		{
			if (player->id_player == id)
				return (player);
			player = player->next;
		}
	}
	return (player);
}

static void add_player(t_player **list, t_player *new_player)
{
	t_player *current;

	if (list && new)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
		{
			*list = new;
		}
	}
}

//I got it from Sergey libft - Sergey is my TeamLead in this poject
// void	list_push_back(t_list *self, void *data)
// {
// 	t_list_item	*item;

// 	if (self && data)
// 	{
// 		item = list_item_create();
// 		item->data = data;
// 		if (self->count == 0)
// 		{
// 			self->head = item;
// 			self->tail = item;
// 		}
// 		else
// 		{
// 			self->tail->next = item;
// 			self->tail = item;
// 		}
// 		self->count++;
// 	}
// }


t_player		*parse_champion(char *filename, int id)
{
	t_player	*player;
	int			fd;

	player = init_player(id);

}

static void	parse_champion_filename(int *argc,
									char ***argv,
									t_vm *vm,
									t_player **list)
{
	int32_t id;

	id = 0;
	if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
	{
		if (!ft_isint(*(*argv + 1), TRUE)
			|| (id = ft_atoi(*(*argv + 1))) < 1
			|| id > 4 // NBR_MAX_PLAYERS
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


// void	parse_dump_part(int *argc, char ***argv, t_vm *vm)
// {
// 		if (!vm->dump_flag && *argc >= 2 && ft_isint(*(*argv + 1), true))
// 		{
// 			if ((vm->dumping_nbr = ft_atoi(*(*argv + 1))) < 0)
// 				vm->dumping_nbr = -1;
// 			if (!ft_strcmp(**argv, "-d"))
// 				vm->dump_flag = 64;
// 			else
// 				vm->dump_flag = 32;
// 			(*argc) -= 2;
// 			(*argv) += 2;
// 		}
// 		else
// 			printf("how to use it");
// }


void	parse_args(int argc, char **argv, t_vm *vm)
{
	t_player *list;
	
	list = NULL; //here we have to add player переделаю как у Серёги в либе листы реализованы
	
	argc--;
	argv++;
	
	while (argc >= 1)
	{
		if (!ft_strcmp(*argv, "-dump") || !ft_strcmp(*argv, "-d"))
		{
			parse_dump_part(&argc, &argv, vm);
		}
		else if (!ft_strcmp(*argv, "-n") || is_filename(*argv, ".cor"))
			parse_champion_filename(&argc, &argv, vm, &list);
		else
			printf("call help help help");
	}
	printf("WE HAVE TO SET THE PLYRS TO VM");
}

int		main(int argc, char **argv)
{
	t_vm *vm;
	
	if (argc < 2)
		argv = NULL;
	
	if (argc >= 2)
	{
		vm = initilization_vm();
		printf("Hello");
		parse_args(argc, argv, vm);
		printf("what we write to the DUMP_FLAG %d\n", vm->dump_flag);
		// launch_virtual_machine(vm); запускаем виртуальную машину и курсор в машине))
	}
	return (0);
}
