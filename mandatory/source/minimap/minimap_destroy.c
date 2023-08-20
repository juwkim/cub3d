/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 15:39:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "image.h"

void	minimap_destroy(const t_minimap *const minimap, void *mlx)
{
	if (minimap->img.ptr)
		image_destroy(&minimap->img, mlx);
}
