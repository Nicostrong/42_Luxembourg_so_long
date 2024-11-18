/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:50:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:59:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_info2(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_info2 initialise all integer variables on the structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure to initialise</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_info2(t_info *info)
{
	info->fd = open(info->map_path, O_RDONLY);
	if (info->fd == -1)
		ft_perror_exit_bonus("Error:\n\tMap not readable.", info);
	info->h = 0;
	info->w = 0;
	info->y = 0;
	info->x = 0;
	info->ex_fund = 0;
	info->c_fund = 0;
	info->e_fund = 0;
	info->move_nbr = 0;
	info->p_nbr = 0;
	info->c_nbr = 0;
	info->e_nbr = 0;
	info->enemy_nbr = 0;
	info->on_exit = 0;
	info->img_len = 64;
	info->die = 0;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_imag initialise the first part of all image variables on the 
 * 	structure.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_img(t_info **info)
{
	(*info)->g_img = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/g_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->g_img)
		ft_perror_exit_bonus("Error:\n\tinit g_img failed.", *info);
	(*info)->w_img = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/w2_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->w_img)
		ft_perror_exit_bonus("Error:\n\tinit w_img failed.", *info);
	(*info)->ec_img = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/ec_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->ec_img)
		ft_perror_exit_bonus("Error:\n\tinit ec_img failed.", *info);
	(*info)->eo_img = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/eo_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->eo_img)
		ft_perror_exit_bonus("Error:\n\tinit eo_img failed.", *info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_img2(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_imag2 initialise the second part of all image variables on the 
 * 	structure.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_init_img2(t_info **info)
{
	(*info)->score = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/score.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->score)
		ft_perror_exit_bonus("Error:\n\tinit score failed.", *info);
	(*info)->p_img = mlx_xpm_file_to_image((*info)->mlx, \
		"./images/girl.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->p_img)
		ft_perror_exit_bonus("Error:\n\tinit girl failed.", *info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	t_info	*ft_init_info_bonus(char *path)
 * </summary>
 *
 * <description>
 * 	ft_init_info_bonus allow all memory for the structure and initialise somes 
 * 	variables, and call ft_init_info2 and ft_init_img, ft_init_img2 and 
 * 	ft_init_anim to initialise all variables of the structure.
 * </description>
 *
 * <param type="char *" name="path">path of the map</param>
 *
 * <return>
 * 	a pointer to the structure full initisalized.
 * </return>
 *
 */

t_info	*ft_init_info_bonus(char *path)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_perror_exit_bonus("Error\n\tAllocation for struct info.", NULL);
	info->map_path = ft_strdup(path);
	ft_init_info2(info);
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_perror_exit_bonus("Error:\n\tmlx init failed.", info);
	ft_init_img(&info);
	ft_init_img2(&info);
	ft_init_anim(&info);
	return (info);
}
