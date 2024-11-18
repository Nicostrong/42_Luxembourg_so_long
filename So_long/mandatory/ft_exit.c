/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:10:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:43:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_perror_exit(char *str_error, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_perror_exit print an error message on stderror and free the structure.
 * </description>
 *
 * <param type="char *" name="str_error">string error to print</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	exit with code 1.
 * </return>
 *
 */

int	ft_perror_exit(char *str_error, t_info *info)
{
	ft_putendl_fd(str_error, 2);
	if (info)
		ft_free_info(info);
	exit(EXIT_FAILURE);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_exit(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_exit end the loop and free the structure correctelly before to exit the
 * 	 program.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	exit with code 0.
 * </return>
 *
 */

int	ft_exit(t_info *info)
{
	mlx_loop_end(info->mlx);
	mlx_destroy_image(info->mlx, info->g_img);
	info->g_img = NULL;
	mlx_destroy_image(info->mlx, info->c_img);
	info->c_img = NULL;
	mlx_destroy_image(info->mlx, info->pl_img);
	info->pl_img = NULL;
	mlx_destroy_image(info->mlx, info->pr_img);
	info->pr_img = NULL;
	mlx_destroy_image(info->mlx, info->eo_img);
	info->eo_img = NULL;
	mlx_destroy_image(info->mlx, info->ec_img);
	info->ec_img = NULL;
	mlx_destroy_image(info->mlx, info->w_img);
	info->w_img = NULL;
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	info->win = NULL;
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	info->mlx = NULL;
	ft_free_info(info);
	exit(EXIT_SUCCESS);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_info2(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_free_info2 free the second part of the strucutre.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_free_info2(t_info **info)
{
	if ((*info)->mlx)
	{
		mlx_destroy_display((*info)->mlx);
		free((*info)->mlx);
	}
	free(*info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_info(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_info free the first part of the strucutre and call ft_free_info2 for
 * 	the second part of the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_info(t_info *info)
{
	if (!info)
		return ;
	if (info->fd)
		close(info->fd);
	if (info->map_path)
		free(info->map_path);
	if (info->map)
		ft_free_array(info->map);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->g_img)
		mlx_destroy_image(info->mlx, info->g_img);
	if (info->w_img)
		mlx_destroy_image(info->mlx, info->w_img);
	if (info->pl_img)
		mlx_destroy_image(info->mlx, info->pl_img);
	if (info->pr_img)
		mlx_destroy_image(info->mlx, info->pr_img);
	if (info->c_img)
		mlx_destroy_image(info->mlx, info->c_img);
	if (info->ec_img)
		mlx_destroy_image(info->mlx, info->ec_img);
	if (info->eo_img)
		mlx_destroy_image(info->mlx, info->eo_img);
	ft_free_info2(&info);
}
