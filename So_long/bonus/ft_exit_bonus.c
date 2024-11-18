/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:10:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:44:54 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_perror_exit_bonus(char *str_error, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_perror_exit_bonus print an error message on stderror and free the 
 * 	structure.
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

int	ft_perror_exit_bonus(char *str_error, t_info *info)
{
	ft_putendl_fd(str_error, 2);
	if (info)
		ft_free_info_bonus(info);
	exit(EXIT_FAILURE);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_exit_bonus(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_exit_bonus end the loop and free the structure correctelly before to exit
 * 	 the program.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	exit with code 0.
 * </return>
 *
 */

int	ft_exit_bonus(t_info *info)
{
	mlx_loop_end(info->mlx);
	ft_free_info_bonus(info);
	exit(EXIT_SUCCESS);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_free_window(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_window free the both windows and the mlx pointer.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_window(t_info *info)
{
	if (info->win)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		info->win = NULL;
	}
	if (info->g_o_win)
	{
		mlx_clear_window(info->mlx, info->g_o_win);
		mlx_destroy_window(info->mlx, info->g_o_win);
		info->g_o_win = NULL;
	}
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		info->mlx = NULL;
	}
}
