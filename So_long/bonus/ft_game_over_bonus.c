/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:32:25 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/15 10:41:00 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	close_game_over(t_info *info)
 * </summary>
 *
 * <description>
 * 	close_game_over count 5 secondes and exit the programm.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static int	close_game_over(t_info *info)
{
	time_t	current_time;

	current_time = time(NULL);
	if (difftime(current_time, info->start_time) >= 5)
	{
		mlx_clear_window(info->mlx, info->g_o_win);
		ft_exit_bonus(info);
	}
	return (0);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_game_over(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_game_over initialise the window and the image for Game Over.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_game_over(t_info **info)
{
	(*info)->g_o_w = 480;
	(*info)->g_o_h = 256;
	(*info)->g_o_win = mlx_new_window((*info)->mlx, (*info)->g_o_w, \
		(*info)->g_o_h, "Game Over");
	if (!(*info)->g_o_win)
		ft_perror_exit_bonus("Error:\n\tGame Over window failed.", *info);
	(*info)->game_over = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/g_o.xpm", &(*info)->g_o_w, &(*info)->g_o_h);
	if (!(*info)->game_over)
		ft_perror_exit_bonus("Error:\n\tgame_over to image failed.", *info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_game_over(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_game_over create a new window to put an image "Game Over" and exit the 
 * 	game after 5 sec.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_game_over(t_info *info)
{
	ft_init_game_over(&info);
	info->start_time = time(NULL);
	mlx_put_image_to_window(info->mlx, info->g_o_win, info->game_over, 0, 0);
	ft_putendl_fd("I CATCH YOU LITTLE GIRL HA HA HA HA HA HA HA !!!!!", 1);
	mlx_loop_hook(info->mlx, (int (*)(void *))close_game_over, info);
	mlx_loop(info->mlx);
}
