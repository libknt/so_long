/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:14:08 by keys              #+#    #+#             */
/*   Updated: 2023/01/18 16:42:30 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_make(t_data *data)
{
	//mlx_init() は正しいグラフィックシステムへの接続を確立し、
	//現在のmlxインスタンスの場所を保持するvoid *を返す．実体
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free_data(&data, 1, "Could not initialize mlx.");
	//windowの作成
	// data->mlx_win = mlx_new_window(data->mlx, 600, 700, "Hello world!");
	data->mlx_win = mlx_new_window(data->mlx, WINSIZ * (data->width), WINSIZ
			* (data->hight), "so_long");
	//image_init
	mlx_image_init(data);
	//フレームごとにft_paintingを呼び出している．windowをペイント
	mlx_loop_hook(data->mlx, ft_painting, data);
	//mlx_hook = eventへのhook 2 = key press, 17 = 破棄通知， 1L<<0 = キープレスマスク， 1L<<2 = ボタンプレスマスク mask= 保護的な
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_map_swap, data);
	//破棄通知というイベント, ボタンがプレスされたときに入る．
	mlx_hook(data->mlx_win, 17, 1L << 2, ft_mlx_destroy, data);
	mlx_loop(data->mlx);
}

//////////////////////////////////////////////////////////////////
//						minilibxのman							//
//		https://harm-smits.github.io/42docs/libs/minilibx		//
//////////////////////////////////////////////////////////////////
