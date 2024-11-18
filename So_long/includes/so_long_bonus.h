/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:40:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 14:44:10 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*
 *	Standard library
 */

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>

/*
 *	Personal library
 */

# include "../library/libft/libft.h"
# include "../library/gnl/get_next_line.h"
# include "../library/mlx_linux/mlx.h"

/*
 *	define
 */

# define TITLE					"Run Girl RUUUUUNNNNNNNNN !!!!!!!!"
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define SPEED_PLAYER			10000
# define SPEED_COL				50000
# define SPEED_ENEMY			20000

/*
 *	strucutures
 */

typedef struct s_anim
{
	int		speed;
	int		chrono;
	int		cur_img;
	int		nb_img;
	void	**array_img;
}			t_anim;

/*
 *	INFO MAP
 *	1 = MUR
 *	0 = SOL
 *	E = EXIT
 *	C = COLLECTABLE
 *	B = ENEMY
 *	V = ENEMY ON COLLECTABLE
 *	N = ENEMY ON EXIT
 *	P = PLAYER
 *	L = PLAYER LEFT
 *	R = PLAYER RIGHT
 *	U = PLAYER UP
 *	D = PLAYER DOWN
 */

typedef struct s_info
{
	char	*map_path;		//	path of the map	
	char	**map;			//	map array
	int		fd;				//	file descriptor
	int		h;				//	height
	int		w;				//	width
	int		y;				//	point y of player
	int		x;				//	point x of player
	int		ex_fund;		//	if exit is fund
	int		c_fund;			//	nbr of collectables fund
	int		e_fund;			//	nbr of exit fund
	int		move_nbr;		//	number of move
	int		p_nbr;			//	number of player
	int		c_nbr;			//	number of collectable
	int		e_nbr;			//	number of exit
	int		enemy_nbr;		//	number of enemy
	int		g_o_w;			//	width of lose image
	int		g_o_h;			//	height of lose image
	int		on_exit;		//	if P on E and C in map
	int		die;			//	if your die
	int		img_len;		//	dim of the image (64 x 64)
	int		**enemy_pos;	//	all position of all enemy
	void	*mlx;			//	mlx api
	void	*win;			//	windows
	void	*g_o_win;		//	windows Game Over
	void	*game_over;		//	GAME OVER image
	void	*score;			//	background for score
	void	*g_img;			//	sol image
	void	*w_img;			//	wall image
	void	*ec_img;		//	exit close image
	void	*eo_img;		//	exit open img
	void	*p_img;			//	player img
	t_anim	*pu_anim;		//	animation of player up
	t_anim	*pd_anim;		//	animation of player down
	t_anim	*pl_anim;		//	animation of player left
	t_anim	*pr_anim;		//	animation of player right
	t_anim	*c_anim;		//	animation of collectable
	t_anim	*b_anim;		//	animation of ennemy
	time_t	start_time;		//	time to close game
}			t_info;

/*
 *	Functions so_long
 */

int		ft_exit_bonus(t_info *info);
int		ft_check_map_width_height(t_info *info);
int		ft_key_press_bonus(int key, t_info *info);
int		ft_check_args_bonus(int argc, char **argv);
int		ft_perror_exit_bonus(char *str_error, t_info *info);

int		*ft_get_all_enemy_move(t_info *info, int id);

void	ft_game_over(t_info *info);
void	ft_check_wall(t_info *info);
void	ft_init_enemy(t_info *info);
void	ft_init_anim(t_info **info);
void	ft_init_p_img(t_info **info);
void	ft_free_window(t_info *info);
void	ft_init_g_o_img(t_info **info);
void	ft_enemy_control(t_info *info);
void	ft_draw_map_bonus(t_info *info);
void	ft_free_info_bonus(t_info *info);
void	ft_parse_map_bonus(t_info *info);
void	ft_check_map_element(t_info *info);
void	ft_check_map_playable_bonus(t_info *info);
void	ft_destroy_anim(t_anim *anim, t_info *info);

t_anim	*ft_init_anim_p(t_info *info, char move);

t_info	*ft_init_info_bonus(char *path);

#endif
