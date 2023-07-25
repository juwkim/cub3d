/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:41:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 03:37:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_sprite(const char *line, enum e_texture *out_tex_id)
{
	if (ft_strncmp(line, "DO ", ft_strlen("DO ")) == 0)
	{
		*out_tex_id = DOOR;
		return (true);
	}
	if (ft_strncmp(line, "IT ", ft_strlen("IT ")) == 0)
	{
		*out_tex_id = ITEM;
		return (true);
	}
	return (false);
}
