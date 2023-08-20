/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:59:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:38:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

// C system headers
# include <math.h>		// To use math related functions
# include <stdio.h>		// To use in and out fuctions
# include <stdlib.h>	// To allocate memory dynamically
# include <string.h>	// To use string utils functions
# include <unistd.h>	// To use primitive system calls
# include <stdbool.h>	// To use true and false
# include <sys/fcntl.h> // TO use file related system calls
# include <X11/X.h>

# include "mlx.h"
# include "libft.h"
# include "list.h"
# include "dlist.h"

# define TITLE		"cub3D"
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# define TEX_WIDTH	64
# define TEX_HEIGHT	64
# define N_WALL		4
# define N_DOOR		1
# define N_SPRITE	1
# define N_BGCOLOR	2
# define N_BGPAD    6

# ifndef M_PI
#  define M_PI		3.14159265358979323846	/* pi */
#  define M_PI_2		1.57079632679489661923	/* pi/2 */
#  define M_PI_4		0.78539816339744830962	/* pi/4 */
# endif // __M_PI__

# ifdef __linux__

enum e_key
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_P = 35,
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_RELESE = 255
};

# else

enum e_key
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_P = 35,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_RELESE = 255
};
# endif // __linux__

enum e_texture
{
	T_SOUTH,
	T_EAST,
	T_NORTH,
	T_WEST,
	T_DOOR,
	T_ITEM,
	T_FLOOR,
	T_CEILING,
	T_SPACE,
	T_NONE
};

enum e_mapchar
{
	C_SOUTH = 'S',
	C_EAST = 'E',
	C_NORTH = 'N',
	C_WEST = 'W',
	C_DOOR = 'D',
	C_ITEM = 'I',
	C_SPACE = '0',
	C_WALL = '1',
	C_EMPTY = ' '
};

typedef uint32_t	t_color;
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_image;

typedef struct s_window
{
	void			*ptr;
	char			*title;
	int				width;
	int				height;
	t_image			img;
	t_image			bg;
	enum e_texture	**tex_id;
	int				**door_idx;
}	t_window;

typedef struct s_minimap
{
	int				width;
	int				height;
	int				alpha;
	int				cam_i;
	int				cam_j;
	t_image			img;
}	t_minimap;

typedef struct s_key
{
	enum e_key	vertical;
	enum e_key	horizontal;
	enum e_key	rotation;
	bool		esc;
	double		rotation_speed;
	double		moving_speed;
}	t_key;

typedef struct s_mouse
{
	int		x;
	int		y;
	bool	left;
	bool	right;
	bool	scroll;
	bool	scroll_up;
	bool	scroll_down;
	bool	window_rotatable;
	double	rotation_speed;
}	t_mouse;

typedef struct s_camera
{
	double	i;
	double	j;
	double	angle;
	double	aof;
}	t_camera;

typedef struct s_texture
{
	t_image	img[N_WALL + N_DOOR + N_SPRITE];
	t_color	bgcolor[N_BGCOLOR];
	int		barrior_dist;
}	t_texture;

typedef struct s_map
{
	enum e_texture	**tex_id;
	uint8_t			**off;
	int				**door_idx;
	int				width;
	int				height;
	t_dlist			list;
}	t_map;

typedef struct s_ray
{
	double			lr;
	double			winfull_dist;
	double			angle;
	enum e_texture	tex_id;
	int				off;
	int				start;
	int				end;
	int				door_idx;
}	t_ray;

typedef struct s_door
{
	int		i;
	int		j;
	int		angle;
	int		angle_closed;
	int		angle_target;
}	t_door;

typedef struct s_item
{
	int		i;
	int		j;
	double	angle;
}	t_item;

typedef struct s_cub3d
{
	void		*mlx;
	t_window	win;
	t_key		key;
	t_mouse		mouse;
	t_camera	cam;
	t_texture	tex;
	t_map		map;
	t_minimap	minimap;
	t_ray		ray;
	t_list		doors;
	t_list		items;
}	t_cub3d;

bool	cub3d_init(t_cub3d *const cub3d, const char *filename);
int		cub3d_destroy(t_cub3d *const cub3d);
int		cub3d_play(t_cub3d *const cub3d);
void	cub3d_render(t_cub3d *const cub3d);
bool	cub3d_update(t_cub3d *const cub3d);

#endif // __CUB3D_BONUS_H__
