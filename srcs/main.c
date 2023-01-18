/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:32:03 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 00:41:03 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_data	*data;

	if (argc != 2)
		return (0);
	ft_new_maps(&maps);
	ft_checks(argv, maps);
	ft_new_data(&data, &maps);
	ft_mlx_make(data);
	ft_free_data(&data, 1, NULL);
}
