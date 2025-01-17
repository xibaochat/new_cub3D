/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 03:32:29 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 18:43:17 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	release(int keycode, t_map *rvar)
{
	if (keycode == ESCAPE_KEY)
	{
		exit(0);
	}
	else if (keycode == W_KEY)
		rvar->open_up = 0;
	else if (keycode == S_KEY)
		rvar->open_down = 0;
	else if (keycode == A_KEY)
		rvar->open_a = 0;
	else if (keycode == D_KEY)
		rvar->open_d = 0;
	else if (keycode == LEFT_ARROW_KEY)
		rvar->open_left = 0;
	else if (keycode == RIGHT_ARROW_KEY)
		rvar->open_right = 0;
	else if (keycode == SHOOTING)
		rvar->shooting = 0;
	else if (keycode == COUTEAU)
		rvar->couteau = 0;
	rvar->nb_press = 0;
	return (0);
}
