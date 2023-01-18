/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:43:26 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 21:13:27 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_square(t_maps *maps)
{
	int		i;
	size_t	width1;
	size_t	width2;

	i = 1;
	if (maps->map[0])
	{
		width1 = ft_strlen(maps->map[0]);
		while (maps->map[i])
		{
			width2 = ft_strlen(maps->map[i]);
			if (width1 != width2)
				ft_free_maps(&maps, 1, "not_sqare");
			i++;
		}
		if (i < 3)
			ft_free_maps(&maps, 1, "not_sqare");
		maps->width = width1;
		maps->hight = i;
	}
	else
		ft_free_maps(&maps, 1, "not_sqare");
}
