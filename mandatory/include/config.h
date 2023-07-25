/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 23:13:40 by juwkim           ###   ########.fr       */
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
# define SPRITE_COUNT			2
# define COLOR_COUNT			2
# define TEX_WIDTH				64
# define TEX_HEIGHT				64
# define M_PI_3					1.0471975512 /* pi/3 */

typedef unsigned int	t_color;

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

enum e_texture
{
	SOUTH,
	EAST,
	NORTH,
	WEST,
	DOOR,
	ITEM,
	SPACE
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
	t_img		tex[TEXTURE_COUNT + SPRITE_COUNT];
	t_color		color[COLOR_COUNT];
	t_camera	cam;
}	t_config;

#endif // __CONFIG_H__
