/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:03:27 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/30 15:35:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_get_all_pos_enemy(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_all_pos_enemy get all position of enemy on the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_get_all_pos_enemy(t_info *info)
{
	int	i;
	int	j;
	int	enemy_i;

	i = -1;
	enemy_i = 0;
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
		{
			if (info->map[i][j] == 'B')
			{
				info->enemy_pos[enemy_i] = (int *)malloc(sizeof(int) * 2);
				if (!info->enemy_pos[enemy_i])
					ft_perror_exit_bonus("Error.\n\tAlloc pos. fail.", info);
				info->enemy_pos[enemy_i][0] = i;
				info->enemy_pos[enemy_i][1] = j;
				enemy_i++;
			}
		}
	}
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_enemy(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_enemy init an array for all position of enemy on the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_init_enemy(t_info *info)
{
	if (info->enemy_nbr < 1)
		return ;
	info->enemy_pos = (int **)malloc(sizeof(int *) * info->enemy_nbr);
	if (!info->enemy_pos)
		ft_perror_exit_bonus("Error.\n\tAlloc enemy pos array fiail.", info);
	ft_get_all_pos_enemy(info);
	srand(time(NULL));
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_enemy_move(t_info *info, int id, int dy, int dx)
 * </summary>
 *
 * <description>
 * 	ft_enemy_move change the position of enemy on the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="id">id of enemy</param>
 * <param type="int" name="dy">delta move on y</param>
 * <param type="int" name="dx">delta move on x</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_enemy_move(t_info *info, int id, int dy, int dx)
{
	int	y;
	int	x;

	y = info->enemy_pos[id][0];
	x = info->enemy_pos[id][1];
	if (info->map[y][x] == 'V')
		info->map[y][x] = 'C';
	else if (info->map[y][x] == 'N')
		info->map[y][x] = 'E';
	else
		info->map[y][x] = '0';
	if (ft_strchr("PUDLR", info->map[y + dy][x + dx]))
	{
		info->die = 1;
		info->map[y + dy][x + dx] = 'B';
		return ;
	}
	if (info->map[y + dy][x + dx] == 'C')
		info->map[y + dy][x + dx] = 'V';
	else if (info->map[y + dy][x + dx] == 'E')
		info->map[y + dy][x + dx] = 'N';
	else
		info->map[y + dy][x + dx] = 'B';
	info->enemy_pos[id][0] += dy;
	info->enemy_pos[id][1] += dx;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_enemy_control(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_enemy_control change all position of all enemy on the map.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_enemy_control(t_info *info)
{
	int	i;
	int	*d;
	int	count;
	int	n;

	i = -1;
	while (++i < info->enemy_nbr)
	{
		d = ft_get_all_enemy_move(info, i);
		count = -1;
		while (++count < 4 && d[count] != -1)
			;
		n = -1;
		if (d[0] != -1)
			n = rand() % count;
		if (n != -1 && d[n] == 0)
			ft_enemy_move(info, i, -1, 0);
		else if (n != -1 && d[n] == 1)
			ft_enemy_move(info, i, 0, -1);
		else if (n != -1 && d[n] == 2)
			ft_enemy_move(info, i, 1, 0);
		else if (n != -1 && d[n] == 3)
			ft_enemy_move(info, i, 0, 1);
		free(d);
	}
}
