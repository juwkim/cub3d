/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set_bgcolor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:43:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 22:04:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static void	array_free(void **const arr);
static int	array_length(void **const arr);
static bool	rgb_to_color(char **rgb, t_color *const color);
static int	atoi_s(const char *str, int *const out_num);

bool	texture_set_bgcolor(t_texture *const tex, const char *line, \
	const enum e_texture id)
{
	char	**rgb;
	bool	res;

	if (tex->bgcolor[id - N_BGPAD] != 256)
	{
		printf("Error\nDuplicated color\n");
		return (false);
	}
	rgb = ft_split(line, ',');
	if (rgb == NULL)
		return (false);
	if (array_length((void **)rgb) != 3)
	{
		printf("Error\ncolor channel is %d, not 3\n", array_length((void **)rgb));
		return (false);
	}
	res = rgb_to_color(rgb, &tex->bgcolor[id - N_BGPAD]);
	array_free((void **)rgb);
	return (res);
}

static void	array_free(void **const arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	array_length(void **const arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

static bool	rgb_to_color(char **rgb, t_color *const color)
{
	int	i;
	int	num;

	i = 0;
	while (rgb[i] != NULL)
	{
		if (atoi_s(rgb[i], &num) == false)
			return (false);
		if ((0 <= num && num <= 255) == false)
		{
			printf("Error\ncolor[%d] is not in range 0 ~ 255\n", i);
			return (false);
		}
		*color = (*color << 8) | num;
		++i;
	}
	return (true);
}

static int	atoi_s(const char *str, int *const out_num)
{
	int			sign;
	long long	num;

	sign = 1;
	if (*str == '-')
	{
		++str;
		sign = -1;
	}
	num = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == false)
			return (false);
		num = num * 10 + (*str++ - '0');
		if ((sign == 1 && num > INT32_MAX) || (sign == -1 && num > -INT32_MIN))
			return (false);
	}
	*out_num = (int)(num * sign);
	return (true);
}
