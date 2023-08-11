/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:12:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:01:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub3d.h"

bool	ray_init(t_ray *const ray, const double lr, const double bof);
void	ray_destroy(t_ray *const ray);
void	ray_cast(t_ray *const ray, const t_camera *const cam, \
	const t_map *const map, const t_window *const win, \
	t_texture *const tex);

#endif // __RAY_H__
