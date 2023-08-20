/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:27:03 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:39:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "window_bonus.h"
#include "key_bonus.h"
#include "mouse_bonus.h"
#include "camera_bonus.h"
#include "texture_bonus.h"
#include "map_bonus.h"
#include "ray_bonus.h"

int	cub3d_destroy(t_cub3d *const cub3d)
{
	(void)cub3d;
	exit(EXIT_SUCCESS);
	return (0);
}
