/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 05:02:24 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "game.h"

// texture.c
void	parse_texture(t_game *const game, const int fd);

// map.c
void	parse_map(t_game *const game, const int fd);

// map_utils.c
void	map_to_int(t_map *const map);
void	trim_map(char **const board, const int map_size);

#endif // __PARSE_H__
