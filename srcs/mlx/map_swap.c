/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:35:03 by keys              #+#    #+#             */
/*   Updated: 2022/12/12 16:32:01 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_swap(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static void	ft_print_step(t_data *data)
{
	data->steps++;
	ft_putstr_fd("I walked", 1);
	ft_putnbr_fd(data->steps, 1);
	ft_putendl_fd(" times.", 1);
}

static void	ft_map_swap_utils(t_data *data, int y, int x)
{
	int	ix;
	int	jy;

	ix = data->player_x;
	jy = data->player_y;
	if (data->map[jy + y][ix + x] != '1')
	{
		if (data->map[jy + y][ix + x] == 'E')
		{
			if (!(data->maps->collection_num))
				ft_close(-1, data);
			return ;
		}
		if (data->map[jy + y][ix + x] == 'C')
		{
			data->maps->collection_num--;
			data->map[jy + y][ix + x] = '0';
		}
		ft_swap(&(data->map[jy][ix]), &(data->map[jy + y][ix + x]));
		ft_print_step(data);
		data->player_y += y;
		data->player_x += x;
	}
}

int	ft_map_swap(int key_num, t_data *data)
{
	if (key_num == ESC_KEY)
		ft_close(ESC_KEY, data);
	if (key_num == W_KEY)
		ft_map_swap_utils(data, -1, 0);
	if (key_num == D_KEY)
		ft_map_swap_utils(data, 0, 1);
	if (key_num == A_KEY)
		ft_map_swap_utils(data, 0, -1);
	if (key_num == S_KEY)
		ft_map_swap_utils(data, 1, 0);
	return (0);
}
