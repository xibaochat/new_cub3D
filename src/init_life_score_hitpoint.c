/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life_score_hitpoint.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:51:27 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:51:40 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player_stats(t_map *r)
{
	r->score = 0;
	r->hitpoint = 100;
	r->lucky_value = 0;
}
