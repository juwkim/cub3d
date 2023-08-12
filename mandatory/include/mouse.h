/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:34:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 14:51:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "cub3d.h"

bool	mouse_init(t_mouse *const mouse, const double rotate_speed);
void	mouse_destroy(const t_mouse *const mouse);
int		mouse_press(int keycode, int x, int y, t_cub3d *const cub3d);
int		mouse_release(int keycode, int x, int y, t_cub3d *const cub3d);

#endif // __MOUSE_H__
