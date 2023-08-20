/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:46:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_bonus.h"

void	image_destroy(const t_image *const img, void *mlx)
{
	mlx_destroy_image(mlx, img->ptr);
}
