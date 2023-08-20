/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:30:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_bonus.h"

t_color	*image_address(const t_image *const img, const int i, const int j)
{
	const char	*addr = img->addr + i * img->len + j * (img->bpp / 8);

	return ((t_color *)addr);
}
