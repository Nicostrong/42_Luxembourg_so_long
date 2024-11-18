/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:17:05 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:53:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_anim(t_anim *anim, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_anim free a structure t_anim.
 * </description>
 *
 * <param type="t_anim *" name="anim">anim struct to free</param>
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_free_anim(t_anim *anim, t_info *info)
{
	int	index;

	index = 0;
	if (anim->array_img)
	{
		while (index < anim->nb_img && anim->array_img[index])
		{
			mlx_destroy_image(info->mlx, anim->array_img[index]);
			anim->array_img[index] = NULL;
			index++;
		}
		free(anim->array_img);
		anim->array_img = NULL;
		free(anim);
		anim = NULL;
	}
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_enemy_array(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_enemy_array free position of enemy on the map. 
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_free_enemy_array(t_info *info)
{
	int	index;

	index = -1;
	while (++index < info->enemy_nbr)
	{
		free(info->enemy_pos[index]);
		info->enemy_pos[index] = NULL;
	}
	free(info->enemy_pos);
	info->enemy_pos = NULL;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_images(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_images free all images on the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_free_images(t_info *info)
{
	if (info->g_img)
		mlx_destroy_image(info->mlx, info->g_img);
	if (info->w_img)
		mlx_destroy_image(info->mlx, info->w_img);
	if (info->p_img)
		mlx_destroy_image(info->mlx, info->p_img);
	if (info->ec_img)
		mlx_destroy_image(info->mlx, info->ec_img);
	if (info->eo_img)
		mlx_destroy_image(info->mlx, info->eo_img);
	if (info->score)
		mlx_destroy_image(info->mlx, info->score);
	if (info->game_over)
		mlx_destroy_image(info->mlx, info->game_over);
	if (info->enemy_pos)
		ft_free_enemy_array(info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_all_anim(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_all_anim free all t_anim structures.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_free_all_anim(t_info *info)
{
	if (info->b_anim)
		ft_free_anim(info->b_anim, info);
	if (info->c_anim)
		ft_free_anim(info->c_anim, info);
	if (info->pu_anim)
		ft_free_anim(info->pu_anim, info);
	if (info->pd_anim)
		ft_free_anim(info->pd_anim, info);
	if (info->pl_anim)
		ft_free_anim(info->pl_anim, info);
	if (info->pr_anim)
		ft_free_anim(info->pr_anim, info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_info_bonus(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_info_bonus free the structure if it's allocated and call other 
 * 	function to free all part of the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_info_bonus(t_info *info)
{
	if (!info)
		return ;
	if (info->fd)
		close(info->fd);
	if (info->map_path)
		free(info->map_path);
	if (info->map)
		ft_free_array(info->map);
	ft_free_images(info);
	ft_free_all_anim(info);
	ft_free_window(info);
	free(info);
}
