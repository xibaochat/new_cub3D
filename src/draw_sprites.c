/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:34:17 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:43:28 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calculation_drawing_sprite(t_spr *spr, t_map *rvar)
{
	spr->sprite_x = spr->x - rvar->pos_x;
	spr->sprite_y = spr->y - rvar->pos_y;
	spr->inv_det = 1.0 / (rvar->plane_x * rvar->dir_y - \
	rvar->dir_x * rvar->plane_y);
	spr->transform_x = spr->inv_det * \
	(rvar->dir_y * spr->sprite_x - rvar->dir_x * spr->sprite_y);
	spr->transform_y = spr->inv_det * (-rvar->plane_y * spr->sprite_x\
	+ rvar->plane_x * spr->sprite_y);
	spr->sprite_screen_x = ((rvar->width / 2) * \
	(1 + spr->transform_x / spr->transform_y));
	spr->sprite_height = abs((int)(rvar->height / (spr->transform_y)));
	spr->draw_start_y = -spr->sprite_height / 2 + rvar->height / 2;
	if (spr->draw_start_y < 0)
		spr->draw_start_y = 0;
	spr->draw_end_y = spr->sprite_height / 2 + rvar->height / 2;
	if (spr->draw_end_y >= rvar->height)
		spr->draw_end_y = rvar->height - 1;
	spr->sprite_width = abs((int)(rvar->height / spr->transform_y));
	spr->draw_start_x = -spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->draw_start_x < 0)
		spr->draw_start_x = 0;
	spr->draw_end_x = spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->draw_end_x >= rvar->width)
		spr->draw_end_x = rvar->width - 1;
	spr->stripe = spr->draw_start_x;
}

static int	get_total_nb_sprites(t_map *rvar)
{
	int i;
	int total_nb_sprite;

	i = -1;
	total_nb_sprite = 0;
	while (++i < NB_SPRITE)
		total_nb_sprite += rvar->all_spr[i].nb_occur;
	return (total_nb_sprite);
}

void		store_chaque_indi_spr_addr_in_an_array(t_map *rvar,\
			int total_nb_sprite)
{
	int j;
	int k;
	int i;

	i = -1;
	j = -1;
	if (rvar->sprite_order)
		free(rvar->sprite_order);
	if (!(rvar->sprite_order = (t_spr **)malloc(sizeof(t_spr *) \
	* total_nb_sprite)))
		free_program_var(rvar, "Malloc failed in function draw_sprite\n", NULL);
	while (++j < NB_SPRITE)
	{
		k = -1;
		while (++k < rvar->all_spr[j].nb_occur)
			rvar->sprite_order[++i] = rvar->all_spr[j].indi_spr + k;
	}
}

void		draw_sprites(t_map *rvar)
{
	int		i;
	int		total_nb_sprite;

	i = -1;
	total_nb_sprite = get_total_nb_sprites(rvar);
	rvar->nb_spr = total_nb_sprite;
	store_chaque_indi_spr_addr_in_an_array(rvar, total_nb_sprite);
	set_sprites_order(rvar, rvar->sprite_order, total_nb_sprite);
	while (++i < total_nb_sprite)
	{
		if (rvar->sprite_order[i]->hitpoint > 0)
		{
			calculation_drawing_sprite(rvar->sprite_order[i], rvar);
			draw_vertical_sprite(rvar->sprite_order[i], rvar);
		}
	}
}
