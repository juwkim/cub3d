/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:42:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "main.h"

# define LR		0.5f
# define BOF	TEX_WIDTH

typedef struct s_raycast
{
	t_image	*tex;
	int		off;
	int		start;
	int		end;
}	t_raycast;

void	raycasting(t_cub3d *const cub3d, t_camera *const cam, \
	const double direction, t_raycast *raycast);

#endif // __RAYCASTING_H__
