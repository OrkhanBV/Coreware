/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 22:26:57 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/10 16:28:50 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
// # define MEM_SIZE (4*1024)
// # define PLYR_NBRS 4

# include "const.h"
# include "libft.h"
# include "op.h"
# include <fcntl.h>
// # include "ft_printf.h"
// # include "gnl.h"
// # include "list.h"
// #include "../libft/includes/libft.h"
//real libs we have to del it after final
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef	struct			s_process
{
	
}						t_process;

typedef struct			s_player
{
    int32_t             id_player;
    char				*name_plyr;
    char				*comment_plyr;
    uint32_t            code_size;
    uint8_t             *code;
    size_t              current_lives_num;
    size_t              previous_lives_num;
    ssize_t             last_live;
    struct s_player     *next;
}						t_player;

typedef struct			s_vm
{
    uint8_t             war_graund[MEM_SIZE];
	t_player			*players[MAX_PLAYERS];
	int32_t				plyrs_nbr;
	t_player			*plyr_winner; //last_alive
	
	t_process			*processes;//cursor
	size_t				process_num; //cursor_num
	
    size_t				alive_nbr;
    ssize_t				cycles;
    ssize_t				cycles_to_die;
    ssize_t				cycles_to_checking;
    
    size_t				nbr_of_checks;
    
    ssize_t				dumping_nbr; // nbr_cycles;
    int					dump_flag; // print mod
    
    int					log; // ??
    int					checknbr; //??
}						t_vm;

t_vm        *initilization_vm(void);
t_player	*init_player(int id);
void	    parsing_main(int argc, char **argv, t_vm *vm);
t_player	*find_player(t_player *list, int32_t id);

#endif