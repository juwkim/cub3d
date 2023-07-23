/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 09:02:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "game_bonus.h"

// parse.c
void	parse_cub(t_game *const game, const int fd);

// texture.c
void	parse_texture(t_game *const game, const int fd);

// map.c
void	parse_map(t_game *const game, const int fd);

// map_to_int.c
void	map_to_int(t_map *const map);

// trim_map.c
void	trim_map(char **const board, const int map_size);

// door.c
void	fill_door(char **const new, const char **board, \
	const int i, const int j);

#endif // __CUB_BONUS_H__
