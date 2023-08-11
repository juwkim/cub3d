/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:12:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 01:48:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub3d.h"

bool	ray_init(t_ray *const ray, const double lr, const double winfull_dist);
void	ray_destroy(t_ray *const ray);
void	ray_cast(t_cub3d *const cub3d);
void	ray_set(t_cub3d *const cub3d, const double i, const double j);

#endif // __RAY_H__
