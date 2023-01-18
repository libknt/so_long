/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:13:40 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 19:06:32 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **dst)
{
	int	i;

	i = 0;
	if (dst)
	{
		while (dst[i])
		{
			free(dst[i]);
			i++;
		}
		free(dst);
	}
}

void	ft_free_maps(t_maps **maps, int flag, char *error_message)
{
	if (*maps)
	{
		if ((*maps)->map)
			ft_free_map((*maps)->map);
		if ((*maps)->dfs_flag)
			ft_free_map((*maps)->dfs_flag);
		if ((*maps)->fd)
			close((*maps)->fd);
		free(*maps);
		*maps = NULL;
	}
	if (error_message)
		ft_putendl_fd(error_message, 2);
	if (flag == 1)
		exit(EXIT_FAILURE);
}

void	ft_free_data(t_data **data, int flag, char *error_message)
{
	if (*data)
	{
		ft_free_maps(&(*data)->maps, 0, error_message);
		free(*data);
	}
	if (flag == 1)
	{
		exit(EXIT_FAILURE);
	}
}
