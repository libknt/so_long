/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:32:03 by keys              #+#    #+#             */
/*   Updated: 2023/01/18 16:09:25 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_data	*data;

	///argv　./so_long {map}
	if (argc != 2)
		return (0);
	//mapの作成と初期化
	ft_new_maps(&maps);
	//map_check
	ft_checks(argv, maps);
	//dataの作成と初期化
	ft_new_data(&data, &maps);
	//minilibxを用いて，game作成
	ft_mlx_make(data);
	//free
	ft_free_data(&data, 1, NULL);
}
