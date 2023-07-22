/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 02:28:53 by juwkim           ###   ########.fr       */
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
# include <sys/errno.h>	// To use errno
# include <sys/fcntl.h> // TO use file related system calls

// project headers
# include "mlx.h"		// mlx fuctions
# include "libft.h"		// libft utile functions

# define PROGRAM			"cub3D"
# define WIN_HEIGHT			1080
# define WIN_WIDTH			1920
# define IMAGE_COUNT		4
# define COLOR_COUNT		2

# define LR					0.05f

# define TEX_WIDTH			64
# define TEX_HEIGHT			64

# ifndef M_PI
#  define M_PI 3.14159265358979323846	/* pi */
# endif // __M_PI__

# define AOF				1.0

typedef unsigned int	t_color;

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
	KEY_RELESED = 255
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

enum e_mapchar
{
	C_NORTH = 'N',
	C_SOUTH = 'S',
	C_WEST = 'W',
	C_EAST = 'E',
	C_EMPTY = '0',
	C_FILLED = '1'
};

enum e_wall
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
	NONE
};

typedef struct s_pos
{
	int	i;
	int	j;
}	t_pos;

typedef struct s_img
{
	void	*pixels;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**board;
	int		size;
	int		capacity;
}	t_map;

typedef struct s_player
{
	t_pos	pos;
	double	lookat;
}	t_player;

typedef struct s_texture
{
	t_img	*img;
	int		off;
	int		start;
	int		end;
}	t_texture;

typedef struct s_key
{
	int		vertical;
	int		horizontal;
	int		rotation;
	bool	esc;
}	t_key;

typedef struct s_cub3d
{
	void			*mlx;
	void			*win;
	t_key			key;
	t_img			screen;
	t_map			map;
	t_img			img[IMAGE_COUNT];
	t_color			color[IMAGE_COUNT + COLOR_COUNT];
	t_player		player;
}	t_cub3d;

#endif // __CUB3D_H__
