/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:06:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:10:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_draw_img(t_info *info, char c, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_draw_imp read the map on the structure and for each char, it print the 
 * 	correct image on the window.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 * <param type="char" name="c">char linked to an image</param>
 * <param type="int" name="x">position in x</param>
 * <param type="int" name="y">position in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_draw_img(t_info *info, char c, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->g_img, x, y);
	if (c == '1')
		mlx_put_image_to_window(info->mlx, info->win, info->w_img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(info->mlx, info->win, info->pr_img, x, y);
	else if (c == 'L')
		mlx_put_image_to_window(info->mlx, info->win, info->pl_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(info->mlx, info->win, info->c_img, x, y);
	else if (c == 'E' && info->c_nbr)
		mlx_put_image_to_window(info->mlx, info->win, info->ec_img, x, y);
	else if (c == 'E' && !info->c_nbr)
		mlx_put_image_to_window(info->mlx, info->win, info->eo_img, x, y);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_draw_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_draw_map read the map on the structure and call ft_draw_img for each 
 * 	image on the map.
 * 	it clear the windows before to create a new window.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_draw_map(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
			ft_draw_img(info, info->map[i][j], j * info->img_len, \
				i * info->img_len);
	}
}
