/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:20:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 23:06:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "config.h"

# define MARGIN		32
# define MV_SPEED	5.0f
# define RT_SPEED	0.05f

bool	update(t_config *const config, const t_key *const key);
bool	rotate(t_config *const config, const int rotation, \
	double *const lookat);
bool	move(const t_key *const key, t_camera *const cam, t_pixel **const data);

#endif // __UPDATE_H__
