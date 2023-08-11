/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:14:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/10 01:19:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

bool	ray_init(t_ray *const ray, const double lr, const double bof)
{
	ray->lr = lr;
	ray->bof = bof;
	return (true);
}
