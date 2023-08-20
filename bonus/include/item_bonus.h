/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 02:40:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:45:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_BONUS_H
# define ITEM_BONUS_H

# include "cub3d_bonus.h"

t_item	*item_create(const int i, const int j, const int angle);
void	item_fill_map(t_cub3d *const cub3d, int i, int j);
void	item_render_map(t_cub3d *const cub3d, const t_item *const item);
void	item_remove_map(t_cub3d *const cub3d, const t_item *const item);
bool	item_update(t_cub3d *const cub3d);

int		_item_get_i(const t_item *const item, const int cnt, const int d);
int		_item_get_j(const t_item *const item, const int cnt, const int d);

#endif // __ITEM_BONUS_H__
