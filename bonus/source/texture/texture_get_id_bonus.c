/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:52:03 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"

enum e_texture	texture_get_id(const char *str)
{
	if (ft_strncmp(str, "SO ", ft_strlen("SO ")) == 0)
		return (T_SOUTH);
	if (ft_strncmp(str, "EA ", ft_strlen("EA ")) == 0)
		return (T_EAST);
	if (ft_strncmp(str, "NO ", ft_strlen("NO ")) == 0)
		return (T_NORTH);
	if (ft_strncmp(str, "WE ", ft_strlen("WE ")) == 0)
		return (T_WEST);
	if (ft_strncmp(str, "DO ", ft_strlen("DO ")) == 0)
		return (T_DOOR);
	if (ft_strncmp(str, "IT ", ft_strlen("IT ")) == 0)
		return (T_ITEM);
	if (ft_strncmp(str, "F ", ft_strlen("F ")) == 0)
		return (T_FLOOR);
	if (ft_strncmp(str, "C ", ft_strlen("C ")) == 0)
		return (T_CEILING);
	return (T_NONE);
}
