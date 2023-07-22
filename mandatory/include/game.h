/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 02:54:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

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

# define PROGRAM				"game"
# define WIN_HEIGHT				1080
# define WIN_WIDTH				1920
# define IMAGE_COUNT			4
# define COLOR_COUNT			2
# define DEFAULT_MAP_CAPACITY	1024
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

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_key			key;
	t_img			screen;
	t_map			map;
	t_img			img[IMAGE_COUNT];
	t_color			color[IMAGE_COUNT + COLOR_COUNT];
	t_player		player;
}	t_game;

#endif // __game_H__
