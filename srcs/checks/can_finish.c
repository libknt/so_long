/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_finish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:31:10 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 16:47:23 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_map_copy(t_maps *maps)
{
	int	i;

	i = 0;
	while (i < maps->hight)
	{
		maps->dfs_flag[i] = ft_strdup(maps->map[i]);
		if (!maps->dfs_flag[i])
			ft_free_maps(&maps, 1, "malloc_failure");
		i++;
	}
	maps->dfs_flag[i] = NULL;
}

static void	ft_dfs_flag_ptr(t_maps *maps)
{
	char	**flag;

	flag = (char **)malloc(sizeof(char *) * (maps->hight + 1));
	if (!flag)
		ft_free_maps(&maps, 1, "malloc_failure");
	maps->dfs_flag = flag;
	ft_map_copy(maps);
}

static bool	ft_check_remnant(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	ft_check_can_finish(t_maps *maps)
{
	ft_dfs_flag_ptr(maps);
	ft_goal_search(maps->player_y, maps->player_x, maps);
	if (maps->flag == 0)
		ft_free_maps(&maps, 1, "You can't finish.");
	if (ft_check_remnant(maps->dfs_flag))
		ft_free_maps(&maps, 1, "You can't collect them all.");
	ft_free_map(maps->dfs_flag);
	maps->dfs_flag = NULL;
}
