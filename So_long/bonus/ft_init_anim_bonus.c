/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_anim_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:23:24 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/27 15:31:30 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_c_img(t_info *info, t_anim *col)
 * </summary>
 *
 * <description>
 * 	ft_init_c_image initialise all image of the collectable animation.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="t_anim *" name="col">anim structure for collectable</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_c_img(t_info *info, t_anim *col)
{
	col->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./images/c_img/c0.xpm", &info->img_len, &info->img_len);
	if (!col->array_img[0])
		ft_perror_exit_bonus("Error:\n\tc_0_img load fail.", info);
	col->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./images/c_img/c1.xpm", &info->img_len, &info->img_len);
	if (!col->array_img[1])
		ft_perror_exit_bonus("Error:\n\tc_1_img load fail.", info);
	col->array_img[2] = mlx_xpm_file_to_image(info->mlx, \
		"./images/c_img/c2.xpm", &info->img_len, &info->img_len);
	if (!col->array_img[2])
		ft_perror_exit_bonus("Error:\n\tc_2_img load fail.", info);
	col->array_img[3] = mlx_xpm_file_to_image(info->mlx, \
		"./images/c_img/c3.xpm", &info->img_len, &info->img_len);
	if (!col->array_img[3])
		ft_perror_exit_bonus("Error:\n\tc_3_img load fail.", info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	t_anim	*ft_init_c(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_c initialise the animation for collectable.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	pointer to animation structure of collectable.
 * </return>
 *
 */

static t_anim	*ft_init_c(t_info *info)
{
	t_anim	*col;

	col = (t_anim *)ft_calloc(1, sizeof(t_anim));
	if (!col)
		ft_perror_exit_bonus("Error:\n\tAlloc collectable anim fail.", info);
	col->speed = SPEED_COL;
	col->chrono = 0;
	col->cur_img = 0;
	col->nb_img = 4;
	col->array_img = (void **)ft_calloc(col->nb_img, sizeof(void *));
	if (!col->array_img)
		ft_perror_exit_bonus("Error:\n\tAlloc col_img array fail.", info);
	ft_init_c_img(info, col);
	return (col);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	t_anim	*ft_init_b(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_b initialise the animation for enemy.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	pointer to animation structure of enemy.
 * </return>
 *
 */

static t_anim	*ft_init_b(t_info *info)
{
	t_anim	*bad;

	bad = (t_anim *)ft_calloc(1, sizeof(t_anim));
	if (!bad)
		ft_perror_exit_bonus("Error:\n\tAlloc bad anim fail.", info);
	bad->speed = SPEED_ENEMY;
	bad->chrono = 0;
	bad->cur_img = 0;
	bad->nb_img = 2;
	bad->array_img = (void **)ft_calloc(bad->nb_img, sizeof(void *));
	if (!bad->array_img)
		ft_perror_exit_bonus("Error:\n\tAlloc bad img array fail.", info);
	bad->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./images/b_img/b0.xpm", &info->img_len, &info->img_len);
	bad->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./images/b_img/b1.xpm", &info->img_len, &info->img_len);
	return (bad);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_anim(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_anim  initialise all structure animation on the structure info.
 * </description>
 *
 * <param type="t_info **" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_init_anim(t_info **info)
{
	(*info)->pu_anim = ft_init_anim_p(*info, 'U');
	if (!(*info)->pu_anim)
		ft_perror_exit_bonus("Error:\n\tpu_anim fail", *info);
	(*info)->pd_anim = ft_init_anim_p(*info, 'D');
	if (!(*info)->pd_anim)
		ft_perror_exit_bonus("Error:\n\tpd_anim fail", *info);
	(*info)->pl_anim = ft_init_anim_p(*info, 'L');
	if (!(*info)->pl_anim)
		ft_perror_exit_bonus("Error:\n\tpl_anim fail", *info);
	(*info)->pr_anim = ft_init_anim_p(*info, 'R');
	if (!(*info)->pr_anim)
		ft_perror_exit_bonus("Error:\n\tpr_anim fail", *info);
	(*info)->c_anim = ft_init_c(*info);
	if (!(*info)->c_anim)
		ft_perror_exit_bonus("Error:\n\tc_anim fail", *info);
	(*info)->b_anim = ft_init_b(*info);
	if (!(*info)->b_anim)
		ft_perror_exit_bonus("Error:\n\tb_anim fail", *info);
}
