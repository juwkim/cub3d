/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:20:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 02:29:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "cub3d.h"

# define MARGIN		16
# define MV_SPEED	8.0f
# define RT_SPEED	0.05f

bool	update(t_cub3d *const cub3d, const t_key *const key);

#endif // __UPDATE_H__
