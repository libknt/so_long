/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:25:16 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 01:29:51 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_maps(t_maps **maps)
{
	*maps = (t_maps *)malloc(sizeof(t_maps));
	if (!maps)
		exit(EXIT_FAILURE);
	(*maps)->map = NULL;
	(*maps)->dfs_flag = NULL;
	(*maps)->fd = -1;
	(*maps)->map_flag = 0;
	(*maps)->hight = -1;
	(*maps)->width = -1;
	(*maps)->player_x = -1;
	(*maps)->player_y = -1;
	(*maps)->exit_x = -1;
	(*maps)->exit_y = -1;
	(*maps)->collection_num = -1;
	(*maps)->flag = 0;
}

void	ft_new_data(t_data **data, t_maps **maps)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_free_maps(maps, 1, "malloc_failure");
	(*data)->maps = *maps;
	(*data)->map = (*maps)->map;
	(*data)->player_x = (*maps)->player_x;
	(*data)->player_y = (*maps)->player_y;
	(*data)->width = (*maps)->width;
	(*data)->hight = (*maps)->hight;
	(*data)->steps = 0;
}
