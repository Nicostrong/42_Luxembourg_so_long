/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:50:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:56:54 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		ft_perror_exit("Error:\n\tMap not readable.", info);
	info->h = 0;
	info->w = 0;
	info->y = 0;
	info->x = 0;
	info->move_cnt = 0;
	info->p_nbr = 0;
	info->c_nbr = 0;
	info->e_nbr = 0;
	info->c_fund = 0;
	info->e_fund = 0;
	info->on_exit = 0;
	info->img_len = 64;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_img initialise all image variables on the structure.
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
	(*info)->w_img = mlx_xpm_file_to_image((*info)->mlx,
			"./images/w_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->w_img)
		ft_perror_exit("Error:\n\txpm file w_img to image fail.", *info);
	(*info)->c_img = mlx_xpm_file_to_image((*info)->mlx,
			"./images/c_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->c_img)
		ft_perror_exit("Error:\n\txpm file c_img to image fail.", *info);
	(*info)->pl_img = mlx_xpm_file_to_image((*info)->mlx,
			"./images/pl_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->pl_img)
		ft_perror_exit("Error:\n\txpm file pl_img to image fail.", *info);
	(*info)->pr_img = mlx_xpm_file_to_image((*info)->mlx,
			"./images/pr_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->pr_img)
		ft_perror_exit("Error:\n\txpm file pr_img to image fail.", *info);
	(*info)->ec_img = mlx_xpm_file_to_image((*info)->mlx,
			"./images/ec_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->ec_img)
		ft_perror_exit("Error:\n\txpm file ec_img to image fail.", *info);
	(*info)->eo_img = mlx_xpm_file_to_image((*info)->mlx,
			"./images/eo_img.xpm", &(*info)->img_len, &(*info)->img_len);
	if (!(*info)->eo_img)
		ft_perror_exit("Error:\n\txpm file eo_img to image fail.", *info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	t_info	*ft_init_info(char *path))
 * </summary>
 *
 * <description>
 * 	ft_init_info allow all memory for the structure and initialise somes 
 * 	variables, and call ft_init_info2 and ft_init_img to initialise all 
 * 	variables of the structure.
 * </description>
 *
 * <param type="char *" name="path">path of the map</param>
 *
 * <return>
 * 	a pointer to the structure full initisalized.
 * </return>
 *
 */

t_info	*ft_init_info(char *path)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_perror_exit("Error\n\tAllocation for struct info.", NULL);
	info->map_path = ft_strdup(path);
	if (!info->map_path)
		ft_perror_exit("Error:\n\tDuplication map_path.", info);
	ft_init_info2(info);
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_perror_exit("Error:\n\tmlx init fail.", info);
	info->g_img = mlx_xpm_file_to_image(info->mlx,
			"./images/g_img.xpm", &info->img_len, &info->img_len);
	if (!info->g_img)
		ft_perror_exit("Error:\n\txpm file g_img to image fail.", info);
	ft_init_img(&info);
	return (info);
}
