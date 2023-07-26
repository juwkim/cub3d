/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:43:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

bool	image_init(const t_cub3d *const cub3d, t_image *const img)
{
	img->img = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img->img == NULL)
	{
		perror("image_init()");
		return (false);
	}
	return (true);
}
