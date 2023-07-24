/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:08:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "config.h"

// parse.c
void	parse_cub(t_config *const config, const char *cub_file);

// texture.c
void	parse_texture(t_config *const config, const int fd);

// map.c
void	parse_map(t_config *const config, const int fd);

// map_to_int.c
void	map_to_int(t_map *const map);

// trim_map.c
void	trim_map(char **const board, const int map_size);

#endif // __CUB_H__
