/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:46:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 22:40:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	image_destroy(t_image *img, void *mlx)
{
	mlx_destroy_image(mlx, img->ptr);
	free(img);
}
