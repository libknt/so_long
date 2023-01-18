/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:37:27 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 16:42:29 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_check_can_go(int i, int j, t_maps *maps)
{
	if (maps->dfs_flag[i][j] == 'E')
	{
		maps->dfs_flag[i][j] = '1';
		maps->flag = 1;
		return (false);
	}
	if (maps->dfs_flag[i][j] == '0')
	{
		maps->dfs_flag[i][j] = '!';
		return (true);
	}
	else if (maps->dfs_flag[i][j] == 'C')
	{
		maps->dfs_flag[i][j] = '!';
		return (true);
	}
	return (false);
}

void	ft_goal_search(int i, int j, t_maps *maps)
{
	if (ft_check_can_go(i, j - 1, maps))
		ft_goal_search(i, j - 1, maps);
	if (ft_check_can_go(i - 1, j, maps))
		ft_goal_search(i - 1, j, maps);
	if (ft_check_can_go(i, j + 1, maps))
		ft_goal_search(i, j + 1, maps);
	if (ft_check_can_go(i + 1, j, maps))
		ft_goal_search(i + 1, j, maps);
}
