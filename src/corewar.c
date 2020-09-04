/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:29:55 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/04 20:22:12 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//swift book
//reywanderlikh 
//



int main(int argc, char **argv)
{
	t_vm *vm;
	
	if (argc >= 2)
	{
		init_virtual_machine(vm);
		parse_args(argc, argv, vm);
		// launch_virtual_machine(vm); запускаем виртуальную машину и курсор в машине))
	}
}
