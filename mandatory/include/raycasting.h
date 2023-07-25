/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 02:10:33 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "config.h"

# define LR		0.5f
# define BOF	TEX_WIDTH

typedef struct s_raycast
{
	t_img	*tex;
	int		off;
	int		start;
	int		end;
}	t_raycast;

void	raycasting(t_config *const config, t_camera *const cam, \
	const double direction, t_raycast *raycast);

#endif // __RAYCASTING_H__
