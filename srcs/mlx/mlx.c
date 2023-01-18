/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:14:08 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 17:55:22 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_make(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free_data(&data, 1, "Could not initialize mlx.");
	data->mlx_win = mlx_new_window(data->mlx, WINSIZ * (data->width), WINSIZ
			* (data->hight), "so_long");
	mlx_image_init(data);
	mlx_loop_hook(data->mlx, ft_painting, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_map_swap, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, ft_mlx_destroy, data);
	mlx_loop(data->mlx);
}
