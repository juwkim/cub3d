/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:31:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:21:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	init_rmap(char **const map, const int map_size, t_map *const rmap);
static int	get_map_width(char **const map, const int map_size);

void	set_map(char **const map, const int map_size, t_map *const rmap)
{
	int				i;
	int				j;

	init_rmap(map, map_size, rmap);
	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == C_WALL)
				fill_wall(rmap->data, i * TEX_HEIGHT, j * TEX_WIDTH);
			else if (map[i][j] == C_DOOR)
				fill_door(rmap->data, i * TEX_HEIGHT, j * TEX_WIDTH);
			++j;
		}
		free(map[i]);
		++i;
	}
	free(map);
}

static void	init_rmap(char **const map, const int map_size, t_map *const rmap)
{
	int	i;
	int	j;

	rmap->width = get_map_width(map, map_size) * TEX_WIDTH;
	rmap->height = map_size * TEX_HEIGHT;
	rmap->data = malloc(sizeof(t_pixel *) * rmap->height);
	_assert(rmap->data != NULL, "malloc() failed\n");
	i = 0;
	while (i < rmap->height)
	{
		rmap->data[i] = malloc(sizeof(t_pixel) * rmap->width);
		_assert(rmap->data[i] != NULL, "malloc() failed\n");
		j = 0;
		while (j < rmap->width)
		{
			rmap->data[i][j].tex_id = SPACE;
			++j;
		}
		++i;
	}
}

static int	get_map_width(char **const map, const int map_size)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (i < map_size)
	{
		width = ft_max(width, (int)ft_strlen(map[i]));
		++i;
	}
	return (width);
}
