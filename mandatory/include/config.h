/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 18:11:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

// C system headers
# include <math.h>		// To use math related functions
# include <stdio.h>		// To use in and out fuctions
# include <stdlib.h>	// To allocate memory dynamically
# include <string.h>	// To use string utils functions
# include <unistd.h>	// To use primitive system calls
# include <stdbool.h>	// To use true and false
# include <sys/fcntl.h> // TO use file related system calls

// project headers
# include "mlx.h"		// mlx fuctions
# include "libft.h"		// libft utile functions

# define TITLE					"cub3D"
# define WIN_HEIGHT				1080
# define WIN_WIDTH				1920
# define TEXTURE_COUNT			4
# define COLOR_COUNT			2
# define TEX_WIDTH				64
# define TEX_HEIGHT				64

# ifndef M_PI
#  define M_PI 3.14159265358979323846	/* pi */
# endif // __M_PI__

typedef unsigned int	t_color;

enum e_mapchar
{
	C_NORTH = 'N',
	C_SOUTH = 'S',
	C_WEST = 'W',
	C_EAST = 'E',
	C_SPACE = '0',
	C_WALL = '1',
	C_EMPTY = ' '
};

enum e_texture
{
	SOUTH,
	EAST,
	NORTH,
	WEST
};

enum e_color
{
	FLOOR,
	CEILING
};

typedef struct s_pos
{
	int	i;
	int	j;
}	t_pos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_window
{
	void	*ptr;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_window;

typedef struct s_pixel
{
	uint8_t	tex_id;
	uint8_t	off;
}	t_pixel;

typedef struct s_map
{
	t_pixel	**data;
	int		width;
	int		height;
}	t_map;

typedef struct s_camera
{
	t_pos	pos;
	double	lookat;
}	t_camera;

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

typedef struct s_config
{
	void		*mlx;
	t_window	win;
	t_key		key;
	t_map		map;
	t_img		tex[TEXTURE_COUNT];
	t_color		color[COLOR_COUNT];
	t_camera	cam;
}	t_config;

#endif // __CONFIG_H__
