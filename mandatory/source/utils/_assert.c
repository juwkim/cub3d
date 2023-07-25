/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _assert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:02:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 01:41:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	_assert(bool expr, const char *str)
{
	if (expr == false)
	{
		printf("Error\n%s", str);
		exit(EXIT_FAILURE);
	}
}
