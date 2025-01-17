/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall_texture_id(char *line)
{
	char	*str;
	int		rtr;

	rtr = 0;
	str = NULL;
	if (line[0] && line[1])
	{
		str = ft_strnew(3);
		ft_strncat(str, line, 2);
		if (!ft_strcmp(str, "SO") || !ft_strcmp(str, "NO")
			|| !ft_strcmp(str, "WE") ||
			!ft_strcmp(str, "EA"))
			rtr = 1;
	}
	free_str(str);
	return (rtr);
}

int	map_info_id_all_get(t_map *r)
{
	if (r->so && r->we && r->no && r->ea
	&& r->resolution
	&& r->s && r->ceil_has_color
	&& (r->f || r->f_has_color))
		return (1);
	return (0);
}
