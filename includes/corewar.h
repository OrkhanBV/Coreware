/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 22:26:57 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/04 20:08:08 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

// #include "libft.h"
// # include "ft_printf.h"
// # include "gnl.h"
// # include "list.h"
#include "../libft/includes/libft.h"
//real libs we have to del it after final
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_vm	t_vm;

struct					s_vm
{
    char				*arr_name;
    char				*arr_comment;
    uint8_t             *code;
    int32_t             
};

#endif