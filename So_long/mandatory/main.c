/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:00:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 14:50:09 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 *	so_long
 * </summary>
 *
 * <description>
 *	so_long is a game playing with a map. The programm need to be lauching with 
 *	a path to the map. The map need to be *.ber.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">list of integer to sort</param>
 *
 * <return>
 *	0 in success or 1 in error.
 * </return>
 *
 */

int	main(int argc, char **argv)
{
	t_info	*info;

	ft_check_args(argc, argv);
	info = ft_init_info(argv[1]);
	ft_parse_map(info);
	info->win = mlx_new_window(info->mlx, (info->img_len * info->w),
			(info->img_len * info->h), TITLE);
	if (!info->win)
		ft_perror_exit("Error :\n\tmlx_windows not running.", info);
	ft_draw_map(info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 1L << 0, &ft_key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &ft_exit, info);
	mlx_loop(info->mlx);
}
