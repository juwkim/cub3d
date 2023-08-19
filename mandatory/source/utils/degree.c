/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:14:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 01:17:17 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	degree(const double radian)
{
	const int	deg = (int)round(radian * 180.0f / M_PI);

	return (deg);
}
