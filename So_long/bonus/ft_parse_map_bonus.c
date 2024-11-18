/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:42:59 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/15 10:45:44 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_load_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_load_map read the map file and creat an array with all char on the file.
 * </description>
 *
 * <param type="t_info *" name="info">structure to save the map</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_load_map(t_info *info)
{
	int		i;
	char	*line;

	i = -1;
	info->fd = open(info->map_path, O_RDONLY);
	if (info->fd == -1)
		ft_perror_exit_bonus("Error:\n\tMap not readable.", info);
	info->map = (char **)malloc(sizeof(char *) * (info->h + 1));
	if (!info->map)
		ft_perror_exit_bonus("Error\n\tMalloc map array.", info);
	while (++i < info->h)
	{
		line = get_next_line(info->fd);
		if (line && ft_strncmp(line, "\n", 1))
			info->map[i] = line;
	}
	info->map[i] = NULL;
	close(info->fd);
	get_next_line(-1);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_parse_map_bonus(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_parse_map_bonus make all checking before to create a copy of the map on 
 * 	the structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_parse_map_bonus(t_info *info)
{
	if (!ft_check_map_width_height(info))
		ft_perror_exit_bonus("Error\n\tNot rectangular map.", info);
	ft_load_map(info);
	ft_check_wall(info);
	ft_check_map_element(info);
	ft_init_enemy(info);
	ft_check_map_playable_bonus(info);
}
