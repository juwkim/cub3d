/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:47:38 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 02:49:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	texture_init(t_texture *const tex, const int fd, const int barrior_dist)
{
	tex->barrior_dist = barrior_dist;
	return (true);
}
