/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:14:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

bool	ray_init(t_ray *const ray, const double lr, const double winfull_dist)
{
	ray->lr = lr;
	ray->winfull_dist = winfull_dist;
	return (true);
}
