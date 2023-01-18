/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:33:23 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 16:10:41 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_image_init(t_data *data)
{
	int	hight;
	int	width;

	hight = WINSIZ;
	width = WINSIZ;
	data->wall_image = mlx_xpm_file_to_image(data->mlx, WALL, &hight, &width);
	data->space_image = mlx_xpm_file_to_image(data->mlx, SPACE, &hight, &width);
	data->player_image = mlx_xpm_file_to_image(data->mlx, PLAYER, &hight,
			&width);
	data->collection_image = mlx_xpm_file_to_image(data->mlx, COLL, &hight,
			&width);
	data->exit_image = mlx_xpm_file_to_image(data->mlx, EXIT, &hight, &width);
}
