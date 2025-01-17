/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_imgs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:49:22 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:50:55 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_floor_imgs(t_map *r)
{
	if (!(r->floor_img_ptr = mlx_xpm_file_to_image(r->mlx_ptr, \
		r->f, &(r->width_floor), &(r->height_floor))))
		free_program_var(r, "Fail file to image\n", NULL);
	r->floor_texture = mlx_get_data_addr(r->floor_img_ptr, \
	&(r->floor_bpp), &(r->s_l_floor), &(r->endian));
}

static void	init_score(t_map *r)
{
	int w;
	int h;

	r->score_img = mlx_xpm_file_to_image(r->mlx_ptr, \
	"./textures/score.xpm", &w, &h);
	if (!r->score_img)
		free_program_var(r, "Fail file to image\n", NULL);
}

void		init_hud_imgs(t_map *r)
{
	if (!r->f_has_color && r->f)
		init_floor_imgs(r);
	init_score(r);
}
