/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:59:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/31 07:34:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// C system headers
# include <math.h>		// To use math related functions
# include <stdio.h>		// To use in and out fuctions
# include <stdlib.h>	// To allocate memory dynamically
# include <string.h>	// To use string utils functions
# include <unistd.h>	// To use primitive system calls
# include <stdbool.h>	// To use true and false
# include <sys/fcntl.h> // TO use file related system calls

# ifdef __linux__
#  include "X11/X.h"
# endif

# include "mlx.h"
# include "libft.h"

# define TITLE		"cub3D"
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# define TEX_WIDTH	64
# define TEX_HEIGHT	64
# define N_WALL		4
# define N_DOOR		1
# define N_SPRITE	1
# define N_BGCOLOR	2

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
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_RELESED = 255
};
# endif // __linux__

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

typedef struct s_camera
{
	double	i;
	double	j;
	double	angle;
	double	aof;
	double	rotation_speed;
	double	moving_speed;
}	t_camera;

typedef struct s_key
{
	enum e_key	vertical;
	enum e_key	horizontal;
	enum e_key	rotation;
	bool		esc;
}	t_key;

typedef struct s_map
{
	enum e_texture	**tex_id;
	uint8_t			**off;
	int				width;
	int				height;
}	t_map;

typedef struct s_mouse
{
	double	rotation_speed;
}	t_mouse;

typedef struct s_texture
{
	t_image	img[N_WALL + N_DOOR + N_SPRITE];
	t_color	bgcolor[N_BGCOLOR];
	int		barrior_dist;
}	t_texture;

typedef struct s_window
{
	void	*ptr;
	char	*title;
	int		width;
	int		height;
	t_image	*img;
}	t_window;

typedef struct s_cub3d
{
	void		*mlx;
	t_window	*win;
	t_key		*key;
	t_mouse		*mouse;
	t_camera	*cam;
	t_texture	*tex;
	t_map		*map;
}	t_cub3d;


bool	cub3d_init(t_cub3d *const cub3d);
void	cub3d_destroy(const t_cub3d *const cub3d);
int		cub3d_start(t_cub3d *const cub3d);
int		cub3d_end(const t_cub3d *const cub3d);
void	cub3d_render(t_cub3d *const cub3d);
bool	cub3d_update(t_cub3d *const cub3d);

#endif // __CUB3D_H__
