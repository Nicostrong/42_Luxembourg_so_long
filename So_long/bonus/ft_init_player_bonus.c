/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:32:46 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/27 14:41:34 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_pu(t_info *info, t_anim *player)
 * </summary>
 *
 * <description>
 * 	ft_init_pu initialise all image for player go up.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="t_anim *" name="player">structure animation for player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_pu(t_info *info, t_anim *player)
{
	player->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u0.xpm", &info->img_len, &info->img_len);
	player->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u1.xpm", &info->img_len, &info->img_len);
	player->array_img[2] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u2.xpm", &info->img_len, &info->img_len);
	player->array_img[3] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u3.xpm", &info->img_len, &info->img_len);
	player->array_img[4] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u4.xpm", &info->img_len, &info->img_len);
	player->array_img[5] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u5.xpm", &info->img_len, &info->img_len);
	player->array_img[6] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u6.xpm", &info->img_len, &info->img_len);
	player->array_img[7] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u7.xpm", &info->img_len, &info->img_len);
	player->array_img[8] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u8.xpm", &info->img_len, &info->img_len);
	player->array_img[9] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/up/u9.xpm", &info->img_len, &info->img_len);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_pd(t_info *info, t_anim *player)
 * </summary>
 *
 * <description>
 * 	ft_init_pd initialise all image for player go down.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="t_anim *" name="player">structure animation for player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_pd(t_info *info, t_anim *player)
{
	player->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d0.xpm", &info->img_len, &info->img_len);
	player->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d1.xpm", &info->img_len, &info->img_len);
	player->array_img[2] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d2.xpm", &info->img_len, &info->img_len);
	player->array_img[3] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d3.xpm", &info->img_len, &info->img_len);
	player->array_img[4] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d4.xpm", &info->img_len, &info->img_len);
	player->array_img[5] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d5.xpm", &info->img_len, &info->img_len);
	player->array_img[6] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d6.xpm", &info->img_len, &info->img_len);
	player->array_img[7] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d7.xpm", &info->img_len, &info->img_len);
	player->array_img[8] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d8.xpm", &info->img_len, &info->img_len);
	player->array_img[9] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/down/d9.xpm", &info->img_len, &info->img_len);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_pl(t_info *info, t_anim *player)
 * </summary>
 *
 * <description>
 * 	ft_init_pl initialise all image for player go left.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="t_anim *" name="player">structure animation for player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_pl(t_info *info, t_anim *player)
{
	player->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l0.xpm", &info->img_len, &info->img_len);
	player->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l1.xpm", &info->img_len, &info->img_len);
	player->array_img[2] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l2.xpm", &info->img_len, &info->img_len);
	player->array_img[3] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l3.xpm", &info->img_len, &info->img_len);
	player->array_img[4] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l4.xpm", &info->img_len, &info->img_len);
	player->array_img[5] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l5.xpm", &info->img_len, &info->img_len);
	player->array_img[6] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l6.xpm", &info->img_len, &info->img_len);
	player->array_img[7] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l7.xpm", &info->img_len, &info->img_len);
	player->array_img[8] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l8.xpm", &info->img_len, &info->img_len);
	player->array_img[9] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/left/l9.xpm", &info->img_len, &info->img_len);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_pr(t_info *info, t_anim *player)
 * </summary>
 *
 * <description>
 * 	ft_init_pr initialise all image for player go right.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="t_anim *" name="player">structure animation for player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_pr(t_info *info, t_anim *player)
{
	player->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r0.xpm", &info->img_len, &info->img_len);
	player->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r1.xpm", &info->img_len, &info->img_len);
	player->array_img[2] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r2.xpm", &info->img_len, &info->img_len);
	player->array_img[3] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r3.xpm", &info->img_len, &info->img_len);
	player->array_img[4] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r4.xpm", &info->img_len, &info->img_len);
	player->array_img[5] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r5.xpm", &info->img_len, &info->img_len);
	player->array_img[6] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r6.xpm", &info->img_len, &info->img_len);
	player->array_img[7] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r7.xpm", &info->img_len, &info->img_len);
	player->array_img[8] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r8.xpm", &info->img_len, &info->img_len);
	player->array_img[9] = mlx_xpm_file_to_image(info->mlx, \
		"./images/p_img/right/r9.xpm", &info->img_len, &info->img_len);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	t_anim	*ft_init_anim_p(t_info *info, char move)
 * </summary>
 *
 * <description>
 * 	ft_init_anim_p initialise all structure animation on the structure info for 
 * 	the player.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="char" name="move">direction of move</param>
 *
 * <return>
 * 	a pointer to a structure anim player.
 * </return>
 *
 */

t_anim	*ft_init_anim_p(t_info *info, char move)
{
	t_anim	*player;

	player = (t_anim *)ft_calloc(1, sizeof(t_anim));
	if (!player)
		ft_perror_exit_bonus("Error:\n\tAlloc player right anim fail.", info);
	player->speed = SPEED_PLAYER;
	player->chrono = 0;
	player->cur_img = 0;
	player->nb_img = 10;
	player->array_img = (void **)ft_calloc(player->nb_img, sizeof(void *));
	if (!player->array_img)
		ft_perror_exit_bonus("Error:\n\tAlloc player_r img array fail.", info);
	if (move == 'U')
		ft_init_pu(info, player);
	else if (move == 'D')
		ft_init_pd(info, player);
	else if (move == 'L')
		ft_init_pl(info, player);
	else if (move == 'R')
		ft_init_pr(info, player);
	else
		ft_perror_exit_bonus("Error:\n\tBad param move for init. anim.", info);
	return (player);
}
