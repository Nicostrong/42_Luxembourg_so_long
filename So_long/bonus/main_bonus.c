/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:00:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 16:04:35 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_update_animation(t_anim *anim, int *updated)
 * </summary>
 *
 * <description>
 * 	ft_update_animation increase a counter and compare with a const. If the 
 * 	counter is equal to the constant, it change the value of the current image
 * 	and set an variable updated to 1.
 * </description>
 *
 * <param type="t_anim *" name="anim">animation structure</param>
 * <param type="int *" name="updated">variable to check update</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_update_animation(t_anim *anim, int *updated)
{
	if (anim->chrono++ >= anim->speed)
	{
		anim->chrono = 0;
		anim->cur_img = (anim->cur_img + 1) % anim->nb_img;
		*updated = 1;
	}
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_animation(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_animation is hook function for animation. It change all current image of
 * 	all animation and the position of the eney.
 * </description>
 *
 * <param type="t_info *" name="info">info structure</param>
 *
 * <return>
 * 	the status value of the execusion.
 * </return>
 *
 */

static int	ft_animation(t_info *info)
{
	int	updated;

	updated = 0;
	ft_update_animation(info->pu_anim, &updated);
	ft_update_animation(info->pd_anim, &updated);
	ft_update_animation(info->pl_anim, &updated);
	ft_update_animation(info->pr_anim, &updated);
	ft_update_animation(info->c_anim, &updated);
	if (info->b_anim->chrono++ >= info->b_anim->speed)
	{
		info->b_anim->chrono = 0;
		info->b_anim->cur_img = (info->b_anim->cur_img + 1) \
			% info->b_anim->nb_img;
		updated = 1;
		ft_enemy_control(info);
	}
	if (updated)
		ft_draw_map_bonus(info);
	return (0);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 *	so_long
 * </summary>
 *
 * <description>
 *	so_long is a game playing with a map. The programm need to be lauching with 
 *	a path to the map. The map need to be *.ber. the bonus part include an 
 *	ennemy, so you can die.
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

	ft_check_args_bonus(argc, argv);
	info = ft_init_info_bonus(argv[1]);
	ft_parse_map_bonus(info);
	info->win = mlx_new_window(info->mlx, (info->img_len * info->w), \
		(info->img_len * info->h), TITLE);
	if (!info->win)
		ft_perror_exit_bonus("Error :\n\tmlx_windows not running.", info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 1L << 0, &ft_key_press_bonus, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &ft_exit_bonus, info);
	mlx_loop_hook(info->mlx, (int (*)(void *))ft_animation, info);
	mlx_loop(info->mlx);
}
