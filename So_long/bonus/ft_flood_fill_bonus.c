/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:10:38 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:46:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_flood_fill(char **map, int x, int y, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_flood_fill replace all char 'O' on the map by the char '2' to simulate 
 * 	all path who the player can use on the map.
 * </description>
 *
 * <param type="char **" name="map"></param>
 * <param type="int" name="x">position on x</param>
 * <param type="int" name="y">position on y</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_flood_fill(char **map, int x, int y, t_info *info)
{
	if (x < 1 || y < 1 || x >= info->w || y >= info->h)
		return ;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] == 'C')
		info->c_fund++;
	if (map[y][x] == 'E')
		info->e_fund++;
	map[y][x] = '2';
	if (!(info->e_fund && (info->c_fund == info->c_nbr)))
	{
		ft_flood_fill(map, x, y - 1, info);
		ft_flood_fill(map, x + 1, y, info);
		ft_flood_fill(map, x, y + 1, info);
		ft_flood_fill(map, x - 1, y, info);
	}
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_check_map_playable_bonus(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_map_playable_bonus check if the map is full playble.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void if is playable map or exit with error message.
 * </return>
 *
 */

void	ft_check_map_playable_bonus(t_info *info)
{
	char	**copy_map;

	copy_map = ft_copy_strarray(info->map);
	ft_flood_fill(copy_map, info->x, info->y, info);
	ft_free_array(copy_map);
	if (!(info->e_fund && (info->c_fund == info->c_nbr)))
		ft_perror_exit_bonus("Error\n\tMap not playable.", info);
}
