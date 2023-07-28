/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:34:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 04:36:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "cub3d.h"

typedef struct s_mouse
{
	double	rotation_speed;
}	t_mouse;

bool	mouse_init(t_mouse *const mouse, const double rotate_speed);
void	mouse_destroy(const t_mouse *const mouse);

#endif // __MOUSE_H__
