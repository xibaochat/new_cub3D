/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:30:47 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:45:09 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_door(t_map *rvar)
{
	int		i;
	char	*s;
	char	*s1;

	i = -1;
	rvar->nb_door = 0;
	if (!(rvar->door = (t_door*)malloc(sizeof(t_door) * 5)))
		free_program_var(rvar, "malloc door fail\n", NULL);
	rvar->door->nb_tex = 0;
	while (++i < 5)
	{
		s = ft_strjoin("./textures/door/texture_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		if (!s1)
			free_program_var(rvar, "The str of secret  door path fail\n", NULL);
		rvar->door[i].path = s1;
	}
}
