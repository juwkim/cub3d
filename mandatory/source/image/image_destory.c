/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:46:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:48:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	image_destroy(const t_cub3d *const cub3d, t_image *const img)
{
	mlx_destroy_image(cub3d->mlx, img->img);
}
