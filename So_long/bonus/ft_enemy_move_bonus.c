/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:18:50 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:38:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_eneny_near_player(t_info *info, int id, int *d, int *move)
 * </summary>
 *
 * <description>
 * 	ft_eneny_near_player check if the player is near the enemy and set an array 
 * 	to this direction.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="id">id of enemy</param>
 * <param type="int *" name="d">array of direction</param>
 *
 * <return>
 * 	a value to make all direction of enemy can do.
 * </return>
 *
 */

static int	ft_eneny_near_player(t_info *info, int id, int *d, int *move)
{
	int	y;
	int	x;

	y = info->enemy_pos[id][0];
	x = info->enemy_pos[id][1];
	if (ft_strchr("PUDLR", info->map[y - 1][x]))
		*move = 0;
	if (ft_strchr("PUDLR", info->map[y][x - 1]))
		*move = 1;
	if (ft_strchr("PUDLR", info->map[y + 1][x]))
		*move = 2;
	if (ft_strchr("PUDLR", info->map[y][x + 1]))
		*move = 3;
	if (*move != -1)
	{
		d[0] = *move;
		d[1] = -1;
		d[2] = -1;
		d[3] = -1;
		return (1);
	}
	return (0);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_move_enemy(t_info *info, int id, int *d)
 * </summary>
 *
 * <description>
 * 	ft_move_enemy set an array of all direction enemy can move.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="id">id of enemy</param>
 * <param type="int *" name="d">array of direction</param>
 *
 * <return>
 * 	a value to make all direction of enemy can do.
 * </return>
 *
 */

static void	ft_move_enemy(t_info *info, int id, int *d)
{
	int	x;
	int	y;
	int	i;

	y = info->enemy_pos[id][0];
	x = info->enemy_pos[id][1];
	i = -1;
	if (ft_strchr("PEC0UDLR", info->map[y - 1][x]))
		d[++i] = 0;
	if (ft_strchr("PEC0UDLR", info->map[y][x - 1]))
		d[++i] = 1;
	if (ft_strchr("PEC0UDLR", info->map[y + 1][x]))
		d[++i] = 2;
	if (ft_strchr("PEC0UDLR", info->map[y][x + 1]))
		d[++i] = 3;
	while (++i < 4)
		d[i] = -1;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	*ft_get_all_enemy_move(t_info *info, int id)
 * </summary>
 *
 * <description>
 * 	ft_get_all_enemy_move get for all enemy on the map the next move.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="id">id of enemy</param>
 *
 * <return>
 * 	a value to make all direction of enemy can do.
 * </return>
 *
 */

int	*ft_get_all_enemy_move(t_info *info, int id)
{
	int	*d;
	int	priority_move;

	d = (int *)malloc(sizeof(int) * 4);
	if (!d)
		return (NULL);
	priority_move = -1;
	if (ft_eneny_near_player(info, id, d, &priority_move))
		return (d);
	ft_move_enemy(info, id, d);
	return (d);
}
