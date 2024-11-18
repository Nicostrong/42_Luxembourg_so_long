/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:01:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/15 10:41:17 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_check_ber(char *path)
 * </summary>
 *
 * <description>
 * 	ft_check_ber check the extension of the map passed in argument.
 * </description>
 *
 * <param type="char *" name="path">path with the map</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */

static int	ft_check_ber(char *path)
{
	int		i;

	i = ft_strlen(path);
	if (i < 5)
		return (0);
	if (path[i - 4] != '.' || path[i - 3] != 'b' || path[i - 2] != 'e' || \
			path[i - 1] != 'r')
		return (0);
	return (1);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_check_not_ber(char *path)
 * </summary>
 *
 * <description>
 * 	ft_check_not_ber check if the file is really a .ber file and not a hidden 
 * 	file called ber.
 * </description>
 *
 * <param type="char *" name="path">path with the map</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */

static int	ft_check_not_ber(char *path)
{
	int		index;
	char	**array;

	index = 0;
	array = ft_split(path, '/');
	while (array[index])
		index++;
	if (ft_strlen(array[--index]) < 5)
		return (ft_free_array(array), 0);
	ft_free_array(array);
	return (1);
}

/*
 * <cat>so_long/cat>
 *
 * <summary>
 * 	int	ft_check_open_ber(char *path)
 * </summary>
 *
 * <description>
 * 	ft_check_open_ber check if the file exist and can be reading. 
 * 	file called ber.
 * </description>
 *
 * <param type="char *" name="path">path with the map</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */

static int	ft_check_open_ber(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	int	ft_check_arg_bonus(int argc, char *argv)
 * </summary>
 *
 * <description>
 * 	ft_check_arg_bonus check the number of argument passed at the program.
 * 	check if the map is ber file.
 * 	check if the file isn't an empty file.
 * 	check if the file exist or not.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char *" name="argv">array of arguments</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */

int	ft_check_args_bonus(int argc, char **argv)
{
	if (argc != 2)
		ft_perror_exit_bonus("Error:\n\tUsage : ./so_long [path to map]", NULL);
	if (!ft_check_ber(argv[argc - 1]))
		ft_perror_exit_bonus("Error\n\tMap must be *.ber file.", NULL);
	if (!ft_check_not_ber(argv[argc - 1]))
		ft_perror_exit_bonus("Error:\n\tCached file.", NULL);
	if (!ft_check_open_ber(argv[argc - 1]))
		ft_perror_exit_bonus("Error\n\tMap not exist or not readable.", NULL);
	return (1);
}
