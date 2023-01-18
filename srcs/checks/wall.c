/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:53:31 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 21:40:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_get_wall(t_maps *maps, char c)
{
	char	*wall;

	wall = (char *)malloc(sizeof(char) * (maps->width + 1));
	if (!wall)
		ft_free_maps(&maps, 1, "malloc_failure");
	ft_memset(wall, c, maps->width);
	wall[maps->width] = '\0';
	return (wall);
}

void	ft_check_wall(t_maps *maps)
{
	int		i;
	char	*wall;
	char	c;

	c = '1';
	wall = ft_get_wall(maps, c);
	i = 0;
	while (i < maps->hight)
	{
		if (i == 0 || i == (maps->hight) - 1)
		{
			if (ft_strncmp((maps->map[i]), wall, maps->width))
				ft_free_maps(&maps, 1, "wall_erro_up_down");
		}
		else
		{
			if (ft_strncmp(&maps->map[i][0], &c, 1))
				ft_free_maps(&maps, 1, "wall_error_left");
			if (ft_strncmp(&maps->map[i][maps->width - 1], &c, 1))
				ft_free_maps(&maps, 1, "wall_erro_right");
		}
		i++;
	}
	free(wall);
}
