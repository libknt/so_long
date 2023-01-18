/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:00:53 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 22:03:46 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit(t_maps *maps)
{
	int	i;
	int	e_num;

	e_num = 0;
	i = 1;
	while (i < maps->hight - 1)
	{
		e_num += ft_find_character(maps->map[i], 'E');
		if (e_num == 1)
		{
			maps->exit_y = i;
			ft_set_coordinate(maps->map[i], 'E', &maps->exit_x);
		}
		if (e_num > 1)
			ft_free_maps(&maps, 1, "Many exits");
		i++;
	}
	if (e_num < 1)
		ft_free_maps(&maps, 1, "Where is the exit");
}
