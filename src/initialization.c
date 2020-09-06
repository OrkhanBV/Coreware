/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 20:24:29 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/04 23:53:14 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm    *initilization_vm()
{
    t_vm *vm;
    
    if(!(vm = (t_vm*)malloc(sizeof(t_vm))))
    {
        printf("we cant initial memmory for virtual machine \n");
        exit (0);
    }
    vm->processes = 0;//cursor
    vm->process_num = 0;//cursor_num
    
    // vm->players = NULL;
    vm->plyr_winner = NULL; //last_alive
    vm->alive_nbr = 0;
    
    vm->cycles = 0;
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->cycles_to_checking = 0;
    
    vm->nbr_of_checks = 0;
    
    vm->dumping_nbr = -1;
    vm->dump_flag = 0; // 

    // vm->show_print_mode = -1; //
    
    vm->log = 0; //
    vm->checknbr = 0; //
    //// we have to check how it works??
    return (vm);
}