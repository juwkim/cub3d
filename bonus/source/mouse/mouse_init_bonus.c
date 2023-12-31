/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:33:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:49 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_bonus.h"

bool	mouse_init(t_mouse *const mouse, const double rotate_speed)
{
	mouse->rotation_speed = rotate_speed;
	mouse->left = false;
	mouse->right = false;
	mouse->scroll = false;
	mouse->scroll_up = false;
	mouse->scroll_down = false;
	mouse->window_rotatable = true;
	return (true);
}
