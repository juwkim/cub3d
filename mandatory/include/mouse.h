/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:34:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 11:38:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "main.h"

# define MOUSE_ROTATE_SPEED 0.05f

bool	mouse_rotate(t_cub3d *const cub3d);

#endif // __MOUSE_H__