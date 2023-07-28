/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:20:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:20:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	**append(char **map, const char *line, int *map_size, \
	int *map_capacity);

char	**read_map(const int fd, int *out_map_size)
{
	char	*line;
	char	**map;
	int		map_size;
	int		map_capacity;

	line = ft_get_next_line(fd);
	while (line && ft_strlen(line) == 0)
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	map = (char **)malloc(sizeof(char *) * DEFAULT_MAP_CAPACITY);
	_assert(map != NULL, "malloc() failed\n");
	map_size = 0;
	map_capacity = DEFAULT_MAP_CAPACITY;
	while (line)
	{
		map = append(map, line, &map_size, &map_capacity);
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		_assert(ft_strlen(line) != 0, "Empty line in map\n");
	}
	*out_map_size = map_size;
	return (map);
}

static char	**append(char **map, const char *line, int *map_size, \
	int *map_capacity)
{
	char	**new;

	if (*map_size == *map_capacity)
	{
		*map_capacity <<= 1;
		new = malloc(sizeof(char *) * *map_capacity);
		_assert(new != NULL, "malloc() failed\n");
		ft_memcpy(new, map, sizeof(char *) * *map_size);
		free(map);
		map = new;
	}
	map[*map_size] = (char *)line;
	*map_size += 1;
	return (map);
}
