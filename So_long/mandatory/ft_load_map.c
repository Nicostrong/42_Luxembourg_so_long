/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:40:57 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 15:07:46 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	ft_load_map(t_info *info)
{
	int		i;
	char	*line;

	i = -1;
	info->fd = open(info->map_path, O_RDONLY);
	if (info->fd == -1)
		ft_perror_exit("Error:\n\tMap not readable.", info);
	info->map = (char **)malloc(sizeof(char *) * (info->h + 1));
	if (!info->map)
		ft_perror_exit("Error\n\tMalloc map array.", info);
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
