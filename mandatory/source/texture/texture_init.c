/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:47:38 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 00:11:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	texture_init(t_texture **tex, const int barrior_dist)
{
	int	i;

	*tex = malloc(sizeof(t_texture));
	if (*tex == NULL)
		return (false);
	i = 0;
	while (i < N_WALL + N_DOOR + N_SPRITE)
		(*tex)->img[i++] = NULL;
	(*tex)->barrior_dist = barrior_dist;
	(*tex)->bgcolor[T_FLOOR - N_BGPAD] = 256;
	(*tex)->bgcolor[T_CEILING - N_BGPAD] = 256;
	return (true);
}
