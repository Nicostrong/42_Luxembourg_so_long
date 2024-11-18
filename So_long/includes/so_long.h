/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:09:16 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/07/01 14:45:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
 *	Standard library
 */

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
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

# define TITLE					"I need Diamonds !!!!"
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

/*
 *	strucutures
 */

typedef struct s_info
{
	char	*map_path;	//	path of the map	
	char	**map;		//	map array
	int		fd;			//	file descriptor
	int		h;			//	height
	int		w;			//	width
	int		y;			//	point y of player
	int		x;			//	point x of player
	int		e_fund;		//	if exit is fund
	int		c_fund;		//	nbr of collectables fund
	int		move_cnt;	//	number of move
	int		p_nbr;		//	number of player
	int		c_nbr;		//	number of collectable
	int		e_nbr;		//	number of exit
	int		on_exit;	//	if P on E and C in map
	int		img_len;	//	dim of the image (64 x 64)
	void	*mlx;		//	mlx api
	void	*win;		//	windows
	void	*g_img;		//	sol image
	void	*w_img;		//	wall image
	void	*pl_img;	//	player go left image
	void	*pr_img;	//	player fo right image
	void	*c_img;		//	collectable image
	void	*ec_img;	//	exit close image
	void	*eo_img;	//	exit open img
}			t_info;

typedef struct s_animation
{
	int		speed;
	int		c_nbr_img;
	int		current_frame;
	int		chrono;
}			t_anim;

/*
 *	Functions so_long
 */

int		ft_exit(t_info *info);
int		ft_key_press(int key, t_info *info);
int		ft_check_args(int argc, char **argv);
int		ft_perror_exit(char *str_error, t_info *info);

void	ft_load_map(t_info *info);
void	ft_draw_map(t_info *info);
void	ft_free_info(t_info *info);
void	ft_parse_map(t_info *info);
void	ft_check_map_playable(t_info *info);

t_info	*ft_init_info(char *path);

t_anim	*ft_init_anim(t_info *info);

#endif