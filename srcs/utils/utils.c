/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:54:48 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 00:10:31 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_character(char *line, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			num++;
		i++;
	}
	return (num);
}

void	ft_set_coordinate(char *line, char c, int *x)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
		{
			*x = i;
			return ;
		}
		i++;
	}
}
