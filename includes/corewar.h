/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 22:26:57 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/04 19:31:53 by jremarqu         ###   ########.fr       */
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


typedef struct s_champ	t_champ;

struct					s_champ
{
    char				*arr_name;
    char				*arr_comment;
    unsigned char		*exet_code;
};

#endif