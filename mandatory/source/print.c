/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/22 19:12:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_map(const t_map *const map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		printf("line[%04d]: ", i);
		j = 0;
		while (map->board[i][j])
		{
			if (j / 8 >= 1 && j % 8 == 0)
				printf(" ");
			printf("%c", map->board[i][j]);
			++j;
		}
		++i;
		printf("\n");
		if (i / 8 >= 1 && i % 8 == 0)
			printf("\n");
	}
}
