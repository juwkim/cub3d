/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:14:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 06:06:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	parse_cub(t_game *const game, const int fd)
{
	parse_texture(game, fd);
	parse_map(game, fd);
}
