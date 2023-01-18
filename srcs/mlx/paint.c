/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:34:14 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 16:13:32 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_painting_utils(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->space_image, WINSIZ * x, WINSIZ * y);
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall_image, WINSIZ * x, WINSIZ * y);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player_image, WINSIZ * x, WINSIZ * y);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->exit_image, WINSIZ * x, WINSIZ * y);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->collection_image, WINSIZ * x, WINSIZ * y);
}

int	ft_painting(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->hight)
	{
		x = 0;
		while (x < data->width)
		{
			ft_painting_utils(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
