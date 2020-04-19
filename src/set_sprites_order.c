/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:52:03 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 08:00:14 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sortsprites(t_spr **order, double *dis, int total_nb_sprite)
{
	int		i;
	int		j;
	t_spr	*tmp_order;
	double	tmp_dis;

	i = -1;
	while (++i < total_nb_sprite - 1)
	{
		j = -1;
		while (++j < total_nb_sprite - i - 1)
		{
			if (dis[j] < dis[j + 1])
			{
				tmp_order = order[j + 1];
				tmp_dis = dis[j + 1];
				order[j + 1] = order[j];
				order[j] = tmp_order;
				dis[j + 1] = dis[j];
				dis[j] = tmp_dis;
			}
		}
	}
}

t_spr		**get_sprites_order(t_map *r, t_spr **spr_order, int total_nb_spr)
{
	int		i;
	double	*sprite_distance;

	i = -1;
	sprite_distance = NULL;
	if (!(sprite_distance = (double *)malloc(sizeof(double) * total_nb_spr)))
		ft_error("malloc failed", NULL);
	while (++i < total_nb_spr)
	{
		sprite_distance[i] = pow((r->posX - spr_order[i]->x), 2) +
			pow((r->posY - spr_order[i]->y), 2);
	}
	r->sprite_distance = sprite_distance;
	sortsprites(spr_order, sprite_distance, total_nb_spr);
	return (spr_order);
}
