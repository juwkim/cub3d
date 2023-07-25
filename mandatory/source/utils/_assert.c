/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _assert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:02:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 23:26:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	_assert(const bool expr, const char *const str)
{
	if (expr == false)
	{
		if (str)
			printf("Error\n%s", str);
		else
			perror("Error\n");
		exit(EXIT_FAILURE);
	}
}
