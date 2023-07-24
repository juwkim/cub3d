/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:17:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 18:06:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_boundary(const char **map, const int map_size, \
	const int i, const int j);

void	traverse_map(char **const map, const int map_size, t_camera *const cam)
{
	int	i;
	int	j;
	int	cam_count;

	cam_count = 0;
	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("SENW", map[i][j]) != NULL)
			{
				_assert(cam_count++ == 0, "Cam count > 1\n");
				check_boundary(map, map_size, i, j);
				set_camera(cam, map, i, j);
				map[i][j] = C_SPACE;
			}
			else if (ft_strchr("01 ", map[i][j]) == NULL)
				_assert(false, "Map includes not allowed character\n");
			++j;
		}
		++i;
	}
	_assert(cam_count == 1, "Cam count == 0\n");
}

static void	check_boundary(const char **map, const int map_size, \
	const int i, const int j)
{
	const bool	is_boundary = (i == 0 || j == 0 || i == map_size - 1 || \
		map[i][j + 1] == '\0' || \
		((int)ft_strlen(map[i - 1]) <= j || map[i - 1][j] == C_EMPTY) || \
		((int)ft_strlen(map[i + 1]) <= j || map[i + 1][j] == C_EMPTY) || \
		map[i][j - 1] == C_EMPTY || map[i][j + 1] == C_EMPTY);

	_assert(is_boundary == false, "Map boundary includes not wall character\n");
}

