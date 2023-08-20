/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_is_bgcolor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:22:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"

bool	texture_is_bgcolor(const enum e_texture id)
{
	return (id == T_FLOOR || id == T_CEILING);
}
