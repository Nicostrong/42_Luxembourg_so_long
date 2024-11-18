/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:06:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/30 14:38:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_draw_move_count(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_draw_move_count print the number of move on window.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_draw_move_count(t_info *info)
{
	char	*count_move;
	char	*move_nbr_str;
	int		w;

	count_move = ft_itoa(info->move_nbr);
	move_nbr_str = ft_strjoin("Move count: ", count_move);
	w = (info->w / 2) * 63 - 32;
	mlx_put_image_to_window(info->mlx, info->win, info->score, w, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->score, w + 64, 0);
	mlx_string_put(info->mlx, info->win, w + 32, 32, 0x000000, move_nbr_str);
	free(count_move);
	free(move_nbr_str);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_draw_exit(t_info *info, char c, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_draw_exit print the correct image for the exit.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="char" name="c">char on the map</param>
 * <param type="int" name="x">pos x on the map</param>
 * <param type="int" name="y">pos y on the map</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_draw_exit(t_info *info, char c, int x, int y)
{
	if (c == 'E' && info->c_nbr)
		mlx_put_image_to_window(info->mlx, info->win, info->ec_img, x, y);
	else if (c == 'E' && !info->c_nbr)
		mlx_put_image_to_window(info->mlx, info->win, info->eo_img, x, y);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_draw_img(t_info *info, char c, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_draw_img print the correct image on the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="char" name="c">char on the map</param>
 * <param type="int" name="x">pos x on the map</param>
 * <param type="int" name="y">pos y on the map</param>
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
	else if (c == 'B' || c == 'V' || c == 'N')
		mlx_put_image_to_window(info->mlx, info->win, \
			info->b_anim->array_img[info->b_anim->cur_img], x, y);
	else if (c == 'P')
		mlx_put_image_to_window(info->mlx, info->win, info->p_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(info->mlx, info->win, \
			info->c_anim->array_img[info->c_anim->cur_img], x, y);
	else if (c == 'U')
		mlx_put_image_to_window(info->mlx, info->win, \
			info->pu_anim->array_img[info->pu_anim->cur_img], x, y);
	else if (c == 'D')
		mlx_put_image_to_window(info->mlx, info->win, \
			info->pd_anim->array_img[info->pd_anim->cur_img], x, y);
	else if (c == 'L')
		mlx_put_image_to_window(info->mlx, info->win, \
			info->pl_anim->array_img[info->pl_anim->cur_img], x, y);
	else if (c == 'R')
		mlx_put_image_to_window(info->mlx, info->win, \
			info->pr_anim->array_img[info->pr_anim->cur_img], x, y);
	ft_draw_exit(info, c, x, y);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_draw_map_bonus(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_draw_map_bonus draw all element of the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_draw_map_bonus(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	if (info->die)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		info->win = NULL;
		ft_game_over(info);
	}
	else
	{
		while (++i < info->h)
		{
			j = -1;
			while (++j < info->w)
			{
				ft_draw_img(info, info->map[i][j], j * info->img_len, \
					i * info->img_len);
			}
		}
		ft_draw_move_count(info);
	}
}
