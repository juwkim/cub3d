/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 02:48:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

bool	image_init(t_image *const img, void *mlx, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	if (img->ptr == NULL)
		return (false);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->len, &img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(mlx, img->ptr);
		return (false);
	}
	return (img);
}
