/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:03:36 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 23:08:01 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_filename_check(char *name, t_maps *maps)
{
	size_t	i;

	i = ft_strlen(name);
	if (4 <= i)
	{
		if (ft_strncmp(&name[i - 4], ".ber", 4) == 0)
			return ;
		else
			ft_free_maps(&maps, 1, "Filename is different.");
	}
	else
		ft_free_maps(&maps, 1, "Filename is different.");
}

void	ft_checks(char **argv, t_maps *maps)
{
	ft_filename_check(argv[1], maps);
	ft_make_map(argv[1], maps);
	ft_check_square(maps);
	ft_check_wall(maps);
	ft_check_player(maps);
	ft_check_exit(maps);
	ft_check_collectibles(maps);
	ft_check_use_characters(maps);
	ft_check_can_finish(maps);
}
