/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:16:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:45:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_BONUS_H
# define WALL_BONUS_H

# include "cub3d_bonus.h"

void	wall_fill_map(t_cub3d *const cub3d, int i, int j);
void	wall_fill_map_east(t_cub3d *const cub3d, int i, const int j);
void	wall_fill_map_north(t_cub3d *const cub3d, const int i, int j);
void	wall_fill_map_south(t_cub3d *const cub3d, const int i, int j);
void	wall_fill_map_west(t_cub3d *const cub3d, int i, const int j);

#endif // __WALL_H__
