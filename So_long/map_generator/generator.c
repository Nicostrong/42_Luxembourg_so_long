/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:42:02 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/26 20:00:35 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct s_info
{
	int c_nbr;
	int c_fund;
	int e_fund;
	int	b_fund;
} t_info;

void    ft_flood_fill(char **map, int x, int y, int w, int h, t_info *info);
int	    ft_check_map_playable(char **map, int w, int h, t_info *info);
void    initialize_map(char **map, int width, int height);
void    place_element(char **map, int width, int height, char element);
int     ft_exit(char *error, char **array);
void    generate_map(int w, int h, int nb_col, int nb_bad, int complexity);
char    **ft_copy_strarray(char **array, int height);
void    ft_free_array(char **array, int height);
void    ft_perror_exit(char *error);

void	ft_flood_fill(char **map, int x, int y, int w, int h, t_info *info)
{
	if (x < 1 || y < 1 || x >= w || y >= h)
		return;
	if (map[y][x] == '1' || map[y][x] == '2')
		return;
	if (map[y][x] == 'C')
		info->c_fund++;
	if (map[y][x] == 'E')
		info->e_fund = 1;
	if (map[y][x] == 'B')
		info->b_fund = 1;
	map[y][x] = '2';
	if (!(info->e_fund && (info->c_fund == info->c_nbr)))
	{
		ft_flood_fill(map, x, y - 1, w, h, info);
		ft_flood_fill(map, x + 1, y, w, h, info);
		ft_flood_fill(map, x, y + 1, w, h, info);
		ft_flood_fill(map, x - 1, y, w, h, info);
	}
}

int ft_check_map_playable(char **map, int w, int h, t_info *info)
{
	char **copy_map;

	copy_map = ft_copy_strarray(map, h);
	info->c_fund = 0;
	info->e_fund = 0;
	ft_flood_fill(copy_map, 1, 1, w, h, info);
	ft_free_array(copy_map, h);
	if (!(info->e_fund && (info->c_fund == info->c_nbr)))
		return (0);
	return (1);
}

void initialize_map(char **map, int width, int height)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				map[i][j] = '1';
			else
				map[i][j] = '0';
		}
	}
}

void place_element(char **map, int width, int height, char element)
{
	int x;
	int y;

	x = rand() % (width - 2) + 1;
	y = rand() % (height - 2) + 1;
	while (map[y][x] != '0')
	{
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	}
	map[y][x] = element;
}

int ft_exit(char *error, char **array)
{
	int index;

	index = -1;
	if (array)
	{
		while (array[++index])
			free(array[index]);
		free(array);
	}
	if (error)
	{
		printf("%s\n", error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

char **ft_copy_strarray(char **array, int height)
{
	char **new_array;
	int i, j;

	new_array = (char **)malloc(height * sizeof(char *));
	if (!new_array)
		return NULL;
	i = -1;
	while (++i < height)
	{
		new_array[i] = (char *)malloc(strlen(array[i]) + 1);
		if (!new_array[i])
		{
			ft_free_array(new_array, i);
			return NULL;
		}
		j = -1;
		while (array[i][++j])
			new_array[i][j] = array[i][j];
		new_array[i][j] = '\0';
	}
	return new_array;
}

void ft_free_array(char **array, int height)
{
	int i;

	i = -1;
	while (++i < height)
		free(array[i]);
	free(array);
}

void ft_perror_exit(char *error)
{
	if (error)
	{
		printf("%s\n", error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void generate_map(int w, int h, int nb_col, int nb_bad, int complexity)
{
	char **map;
	int i;
	int j;
	t_info info;

	map = (char **)malloc(h * sizeof(char *));
	if (!map)
		ft_exit("Error:\n\tAlloc map[i].", NULL);
	i = 0;
	while (i < h)
	{
		map[i] = (char *)malloc(w * sizeof(char));
		if (!map[i])
			ft_exit("Error:\n\tAlloc map[i].", map);
		i++;
	}
	initialize_map(map, w, h);
	place_element(map, w, h, 'P');
	place_element(map, w, h, 'E');
	i = -1;
	while (++i < nb_col)
		place_element(map, w, h, 'C');
	i = -1;
	while (++i < nb_bad)
		place_element(map, w, h, 'B');
	i = -1;
	while (++i < complexity)
		place_element(map, w, h, '1');
	info.c_nbr = nb_col;
	if (!ft_check_map_playable(map, w, h, &info))
		generate_map(w, h, nb_col, nb_bad, complexity);
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
			printf("%c", map[i][j]);
		printf("\n");
	}
	ft_exit(NULL, map);
}

int main(int argc, char **argv)
{
	int w;
	int h;
	int nb_col;
	int nb_bad;
	int complexity;

	if (argc != 6)
	{
		printf("Usage: %s <width> <height> <num_collectibles> <num_enemies> <complexity>\n", argv[0]);
		return 1;
	}
	w = atoi(argv[1]);
	h = atoi(argv[2]);
	nb_col = atoi(argv[3]);
	nb_bad = atoi(argv[4]);
	complexity = atoi(argv[5]);
	if (w < 3 || h < 3 || nb_col < 0 || nb_bad < 0 || complexity < 0)
	{
		printf("Invalid parameters.\n");
		return 1;
	}
	srand(time(NULL));
	generate_map(w, h, nb_col, nb_bad, complexity);
	return 0;
}
