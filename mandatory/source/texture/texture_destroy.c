/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:59:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 02:21:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	texture_destroy(const t_texture *const tex, void *mlx)
{
	int	i;

	i = 0;
	while (i < N_WALL + N_DOOR + N_SPRITE)
		image_destroy(tex->img[i++], mlx);
}
