/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:29:55 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/10 16:31:55 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"


int		main(int argc, char **argv)
{
	t_vm *vm;
	
	if (argc < 2)
		argv = NULL;
	
	if (argc >= 2)
	{
		vm = initilization_vm();
		printf("Hello");
		parsing_main(argc, argv, vm);
		// parse_args(argc, argv, vm);
		printf("what we write to the DUMP_FLAG %d\n", vm->dump_flag);
		// launch_virtual_machine(vm); запускаем виртуальную машину и курсор в машине))
	}
	return (0);
}

//swift book
//reywanderlikh 
//