/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_is_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:22:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 04:07:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	texture_is_wall(const enum e_texture id)
{
	return (id == T_SOUTH || id == T_EAST || id == T_NORTH || id == T_WEST);
}
