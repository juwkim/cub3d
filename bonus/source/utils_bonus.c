/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:07:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 06:07:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

bool	is_extension(const char *filename, const char *extension)
{
	const size_t	file_len = ft_strlen(filename);
	const size_t	extension_len = ft_strlen(extension);

	return (file_len > extension_len && \
		ft_strcmp(filename + file_len - extension_len, extension) == 0);
}

void	_assert(bool expr, const char *str)
{
	if (expr == false)
	{
		printf("Error\n%s", str);
		exit(EXIT_FAILURE);
	}
}

int	_atoi(const char *nptr)
{
	int	num;
	int	sign;

	sign = 0;
	if (ft_strchr("+-", *nptr) != NULL)
		sign = (*nptr++ == '-');
	num = 0;
	while (ft_isdigit(*nptr) == true)
		num = num * 10 + (*nptr++ - '0');
	_assert(*nptr == '\0', "color includes nonnumeric character\n");
	if (sign == 1)
		return (-num);
	return (num);
}

int	_strfind(const char *s, char c)
{
	const char	*cur = s;

	while (*cur != '\0' && *cur != c)
		++cur;
	return (cur - s);
}

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
