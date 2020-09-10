/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:50:52 by jremarqu          #+#    #+#             */
/*   Updated: 2020/09/10 16:03:41 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

// void        add_player(t_player **list, t_player *new_player)
// {
// 	t_player *current;

// 	if (list && new_player)
// 	{
// 		if (*list)
// 		{
// 			current = *list;
// 			while (current->next)
// 				current = current->next;
// 			current->next = new_player;
// 		}
// 		else
// 		{
// 			*list = new_player;
// 		}
// 	}
// }

