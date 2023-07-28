/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:47:38 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 00:45:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	texture_init(t_texture *const tex, const int barrior_dist)
{
	tex->barrior_dist = barrior_dist;
	return (true);
}
