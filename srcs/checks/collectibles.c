/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:04:57 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 22:07:37 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_collectibles(t_maps *maps)
{
	int	i;
	int	c_num;

	c_num = 0;
	i = 1;
	while (i < maps->hight - 1)
	{
		c_num += ft_find_character(maps->map[i], 'C');
		i++;
	}
	if (c_num < 1)
		ft_free_maps(&maps, 1, "Where is the collectibles");
	maps->collection_num = c_num;
}
