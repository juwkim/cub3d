/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init_by_xpm_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 02:49:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

bool	image_init_by_xpm_file(t_image *const img, void *mlx, char *xpm_file)
{
	img->ptr = mlx_xpm_file_to_image(mlx, xpm_file, &img->width, &img->height);
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
