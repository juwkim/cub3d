/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:21:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

double	radian(const int degree)
{
	const double	rad = degree * M_PI / 180.0f;

	return (rad);
}
