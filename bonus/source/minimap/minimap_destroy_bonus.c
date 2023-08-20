/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"
#include "image_bonus.h"

void	minimap_destroy(const t_minimap *const minimap, void *mlx)
{
	if (minimap->img.ptr)
		image_destroy(&minimap->img, mlx);
}
