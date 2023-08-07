/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:34:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 23:57:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "cub3d.h"

bool	mouse_init(t_mouse **mouse, const double rotate_speed);
void	mouse_destroy(t_mouse *mouse);

#endif // __MOUSE_H__
