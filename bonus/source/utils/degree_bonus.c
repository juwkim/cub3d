/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:14:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	degree(const double radian)
{
	const int	deg = (int)round(radian * 180.0f / M_PI);

	return (deg);
}
