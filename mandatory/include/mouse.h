/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:34:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/31 07:37:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "cub3d.h"

bool	mouse_init(t_mouse *const mouse, const double rotate_speed);
void	mouse_destroy(const t_mouse *const mouse);

#endif // __MOUSE_H__
