/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:59:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:01:44 by juwkim           ###   ########.fr       */
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

# include "window.h"
# include "key.h"
# include "mouse.h"
# include "camera.h"
# include "map.h"
# include "texture.h"
# include "image.h"
# include "utils.h"

# define TITLE		"cub3D"
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# ifndef M_PI
#  define M_PI		3.14159265358979323846	/* pi */
#  define M_PI_2		1.57079632679489661923	/* pi/2 */
#  define M_PI_4		0.78539816339744830962	/* pi/4 */
# endif // __M_PI__

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
