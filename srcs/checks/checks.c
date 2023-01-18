/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:03:36 by keys              #+#    #+#             */
/*   Updated: 2023/01/18 15:57:41 by keys             ###   ########.fr       */
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
	//filename *.ber
	ft_filename_check(argv[1], maps);
	//get_next_lineを用いて，map.ber　を読み込みmapを作成
	ft_make_map(argv[1], maps);
	//squareかどうかcheck
	ft_check_square(maps);
	//wall がすべて 1かどうかcheck
	ft_check_wall(maps);
	//playerが1人だけいるかどうか．
	ft_check_player(maps);
	//exitが1つだけあるかどうか
	ft_check_exit(maps);
	//collectionが1つ以上あるかどうか
	ft_check_collectibles(maps);
	//使用可能文字以外が使われていないか
	ft_check_use_characters(maps);
	//すべてのcollectionを取得して，exitできるかどうか(dfs)
	ft_check_can_finish(maps);
}
