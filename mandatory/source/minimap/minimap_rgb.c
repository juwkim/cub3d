/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:57:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 16:57:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

t_color	minimap_rgb(const t_minimap *const minimap, const unsigned int r, \
	const unsigned int g, const unsigned int b)
{
	const t_color	color = (minimap->alpha << 24) | (r << 16) | (g << 8) | b;

	return (color);
}
