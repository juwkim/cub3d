/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 04:30:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# include "cub3d.h"

bool	door_update(t_cub3d *const cub3d);
int		door_type(const t_dlist_node *const cur, const int i);
bool	door_is_valid(const t_dlist_node *const cur, const int i);

#endif // __DOOR_H__