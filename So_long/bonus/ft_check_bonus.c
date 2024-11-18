/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/15 10:42:06 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_check_map_width_height(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_map_width_heitgh check if the width and the height are correct.
 * 	a correct map is a rectangular map and a width and a height more of 3.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	1 if the map is correct
 * 	or
 * 	0 if the map isn't correct.
 * </return>
 *
 */

int	ft_check_map_width_height(t_info *info)
{
	char	*line;

	line = get_next_line(info->fd);
	info->w = (int)ft_strlen(line);
	if (info->w < 3)
		return (close(info->fd), get_next_line(-1), free(line), 0);
	info->h = 1;
	while (line && ft_strncmp(line, "\n", 1))
	{
		if (info->w != (int)ft_strlen(line))
			return (close(info->fd), get_next_line(-1), free(line), 0);
		free(line);
		line = get_next_line(info->fd);
		if (line)
			info->h++;
	}
	free(line);
	get_next_line(-1);
	close(info->fd);
	if (info->h < 3)
		return (0);
	return (1);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_check_wall(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_wall check if the map is surrounded by a wall.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	1 if the map is correctly close by a wall
 * 	or
 * 	0 if the map isn't correctly close by a wall.
 * </return>
 *
 */

void	ft_check_wall(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->h)
	{
		if (i == 0 || i == info->h - 1)
		{
			j = -1;
			while (++j < info->w)
				if (info->map[i][j] != '1')
					ft_perror_exit_bonus("Error\n\tT/B wall error.", info);
		}
		else
			if (info->map[i][0] != '1' || info->map[i][info->w - 1] != '1')
				ft_perror_exit_bonus("Error\n\tmiddle wall error.", info);
	}
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_set_player_info(t_info *info, int y, int x)
 * </summary>
 *
 * <description>
 * 	ft_set_player_info set the position of the player on the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="y">position in y</param>
 * <param type="int" name="x">position in x</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_set_player_info(t_info *info, int y, int x)
{
	info->p_nbr++;
	info->y = y;
	info->x = x;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_check_map_element(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_map_element check all elements on the map are corrects.
 * 	a correct element is :
 * 		E => for exit
 * 		P => for player
 * 		C => for collectable
 * 	only one exit and one collectible and minimum one collectable. 
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_check_map_element(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
		{
			if (info->map[i][j] == 'P')
				ft_set_player_info(info, i, j);
			else if (info->map[i][j] == 'C')
				info->c_nbr++;
			else if (info->map[i][j] == 'E')
				info->e_nbr++;
			else if (info->map[i][j] == 'B')
				info->enemy_nbr++;
			else if (info->map[i][j] != '0' && info->map[i][j] != '1')
				ft_perror_exit_bonus("Error\n\tType of element error.", info);
		}
	}
	if (info->p_nbr != 1 || info->c_nbr < 1 || info->e_nbr != 1 \
		|| info->enemy_nbr < 1)
		ft_perror_exit_bonus("Error\n\tNumber of element error in map.", info);
}
