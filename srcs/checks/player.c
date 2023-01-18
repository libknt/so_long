/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:52:56 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 00:12:05 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_player(t_maps *maps)
{
	int	i;
	int	p_num;
	int	flag;

	flag = 0;
	p_num = 0;
	i = 1;
	while (i < maps->hight - 1)
	{
		p_num += ft_find_character(maps->map[i], 'P');
		if (p_num == 1 && flag == 0)
		{
			flag = 1;
			maps->player_y = i;
			ft_set_coordinate(maps->map[i], 'P', &maps->player_x);
		}
		if (p_num > 1)
			ft_free_maps(&maps, 1, "Many players");
		i++;
	}
	if (p_num < 1)
		ft_free_maps(&maps, 1, "Where is the player");
}
