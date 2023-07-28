/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:46:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 03:34:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	image_destroy(const t_image *const img, void *mlx)
{
	mlx_destroy_image(mlx, img->ptr);
}
