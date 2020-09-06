/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 22:26:57 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/04 23:52:50 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
// # define MEM_SIZE (4*1024)
// # define PLYR_NBRS 4

# include "const.h"
# include "libft.h"
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
    char				*arr_name;
    char				*arr_comment;
    uint8_t             *code;
}						t_player;

typedef struct			s_vm
{
    uint8_t             war_graund[MEM_SIZE];
	t_player			*players[PLYR_NBRS];
	int32_t				plyrs_nbr;
	t_player			*plyr_winner; //last_alive
	
	t_process			*processes;//cursor
	size_t				process_num; //cursor_num
	
    size_t				alive_nbr;
    ssize_t				cycles;
    ssize_t				cycles_to_die;
    ssize_t				cycles_to_checking;
    
    size_t				nbr_of_checks;
    
    ssize_t				dumping_nbr;
    int					dump_flag; // ??
    
    int					log; // ??
    int					checknbr; //??
}						t_vm;

t_vm    *initilization_vm(void);

#endif
