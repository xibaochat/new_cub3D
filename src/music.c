/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:57:48 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 10:01:00 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	insert_warn(t_map *r)
{
//	if (r->hitpoint > 0)
		//system("afplay ./sounds/damage.mp3 &");
	r->hitpoint -= 5;
}
