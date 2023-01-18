/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:11:53 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 00:40:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_use_characters(t_maps *maps)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("10PCE");
	if (!tmp)
		ft_free_maps(&maps, 1, "malloc_failure");
	while (i < maps->hight)
	{
		j = 0;
		while (j < maps->width)
		{
			if (ft_strchr(tmp, maps->map[i][j]) == NULL)
			{
				free(tmp);
				ft_free_maps(&maps, 1, "Some characters are not available.");
			}
			j++;
		}
		i++;
	}
	free(tmp);
}
