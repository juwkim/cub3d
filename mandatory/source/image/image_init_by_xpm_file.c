/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init_by_xpm_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:43:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 02:11:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "utils.h"

bool	image_init_by_xpm_file(t_image *const img, void *mlx, char *filename)
{
	if (is_extension(filename, ".xpm") == false)
	{
		printf("Error\nimage is not xpm file\n");
		return (false);
	}
	if (img->ptr != NULL)
	{
		printf("Error\nDuplicated image\n");
		return (false);
	}
	img->ptr = mlx_xpm_file_to_image(mlx, filename, &img->width, &img->height);
	if (img->ptr == NULL)
		return (false);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->len, &img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(mlx, img->ptr);
		return (false);
	}
	return (true);
}
