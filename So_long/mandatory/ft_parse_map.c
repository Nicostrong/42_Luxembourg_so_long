/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:42:59 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:00:06 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_check_empty_file(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_empty_file check if the file is empty or not.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	1 if the file is an empty file
 * 	or
 * 	0 if the file isn't an empty file.
 * </return>
 *
 */

static int	ft_check_empty_file(t_info *info)
{
	int		nb_bytes;
	int		fd;
	char	*buff;

	buff = (char *)malloc(10 * sizeof(char));
	fd = open(info->map_path, O_RDONLY);
	nb_bytes = read(fd, buff, 9);
	if (nb_bytes < 1)
	{
		free(buff);
		close(fd);
		return (1);
	}
	free(buff);
	close(fd);
	return (0);
}

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

static int	ft_check_map_width_height(t_info *info)
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

static void	ft_check_wall(t_info *info)
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
					ft_perror_exit("Error\n\ttop/bottom wall error.", info);
		}
		else
			if (info->map[i][0] != '1' || info->map[i][info->w - 1] != '1')
				ft_perror_exit("Error\n\tmiddle wall error.", info);
	}
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

static void	ft_check_map_element(t_info *info)
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
			{
				info->p_nbr++;
				info->y = i;
				info->x = j;
			}
			else if (info->map[i][j] == 'C')
				info->c_nbr++;
			else if (info->map[i][j] == 'E')
				info->e_nbr++;
			else if (info->map[i][j] != '0' && info->map[i][j] != '1')
				ft_perror_exit("Error\n\tType of element error in map.", info);
		}
	}
	if (info->p_nbr != 1 || info->c_nbr < 1 || info->e_nbr != 1)
		ft_perror_exit("Error\n\tNumber of element error in map.", info);
}

/*
 * <cat>bso_long</cat>
 *
 * <summary>
 * 	void	ft_parse_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_parse_map make all checking before to create a copy of the map on the 
 * 	structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_parse_map(t_info *info)
{
	if (ft_check_empty_file(info))
		ft_perror_exit("Error:\n\tEmpty file.", info);
	if (!ft_check_map_width_height(info))
		ft_perror_exit("Error\n\tNot rectangular map.", info);
	ft_load_map(info);
	ft_check_wall(info);
	ft_check_map_element(info);
	ft_check_map_playable(info);
}
