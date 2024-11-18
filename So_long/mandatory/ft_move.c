/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:20:33 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:01:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_update_position(t_info *info, int new_y, int new_x)
 * </summary>
 *
 * <description>
 * 	ft_update_position update the position of the player on the map array.
 * 	print the count of move made by the player.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 * <param type="int" name="new_y">new position in y</param>
 * <param type="int" name="new_x">new position in x</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_update_position(t_info *info, int new_y, int new_x)
{
	if (info->on_exit)
		info->map[info->y][info->x] = 'E';
	else
		info->map[info->y][info->x] = '0';
	info->on_exit = (info->map[new_y][new_x] == 'E');
	if (info->map[new_y][new_x] == 'C')
		info->c_nbr--;
	if (info->x < new_x)
		info->map[new_y][new_x] = 'P';
	else
		info->map[new_y][new_x] = 'L';
	info->y = new_y;
	info->x = new_x;
	info->move_cnt++;
	ft_putstr_fd("Move count : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putchar_fd('\n', 1);
	ft_draw_map(info);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	static void	ft_move(t_info *info, int dy, int dx)
 * </summary>
 *
 * <description>
 * 	ft_move check if the move to the new position is possible and call the 
 * 	function ft_update_position to update the map on the structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 * <param type="int" name="dy">delta in y</param>
 * <param type="int" name="dx">delta in x</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_move(t_info *info, int dy, int dx)
{
	int		new_y;
	int		new_x;
	char	next_tile;

	new_y = info->y + dy;
	new_x = info->x + dx;
	next_tile = info->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E' && info->c_nbr == 0)
		ft_exit(info);
	else
		ft_update_position(info, new_y, new_x);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_key_press(int key, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_key_press catch the key pressed by the player and call the function 
 * 	ft_move to change the position of the player on the map.
 * 	after each move, it call ft_draw_map to print the new map on the screen.
 * </description>
 *
 * <param type="int" name="key">value of the key pressed on the keyboard</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	1 if the map is updated or 0.
 * </return>
 *
 */

int	ft_key_press(int key, t_info *info)
{
	if (key == XK_Up || key == XK_w)
		ft_move(info, -1, 0);
	else if (key == XK_Left || key == XK_a)
		ft_move(info, 0, -1);
	else if (key == XK_Down || key == XK_s)
		ft_move(info, 1, 0);
	else if (key == XK_Right || key == XK_d)
		ft_move(info, 0, 1);
	else if (key == XK_Escape)
		ft_exit(info);
	else
		return (0);
	return (1);
}
