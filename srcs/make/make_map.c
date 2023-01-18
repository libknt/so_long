/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:42:25 by keys              #+#    #+#             */
/*   Updated: 2023/01/18 15:53:35 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_get_new_line(char *line, t_maps *maps)
{
	size_t	len;
	char	*new_line;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		new_line = ft_substr(line, 0, len - 1);
	else
		return (line);
	if (!new_line)
		ft_free_maps(&maps, 1, "malloc_failure");
	free(line);
	return (new_line);
}

static void	get_double_ptr(t_maps *maps, int i)
{
	maps->map = (char **)malloc((sizeof(char *) * (i + 1)));
	if (!(maps->map))
		ft_free_maps(&maps, 1, "malloc_failure");
	maps->map[i] = NULL;
}

static void	ft_get_map(t_maps *maps, int i)
{
	char	*line;

	line = get_next_line(maps->fd);
	if (!line)
		return (get_double_ptr(maps, i));
	else if (line[0] == '\n')
	{
		if (maps->map_flag == 1)
			maps->map_flag = 2;
		free(line);
		ft_get_map(maps, i);
		return ;
	}
	else
	{
		if (maps->map_flag == 2)
			ft_free_maps(&maps, 1, "map_failure");
		maps->map_flag = 1;
		ft_get_map(maps, i + 1);
		maps->map[i] = ft_get_new_line(line, maps);
	}
}

void	ft_make_map(char *txt, t_maps *maps)
{
	maps->fd = open(txt, O_RDONLY);
	if (maps->fd < 0)
	{
		free(maps);
		exit(EXIT_FAILURE);
	}
	//再帰関数を用いmapを作成
	ft_get_map(maps, 0);
}
