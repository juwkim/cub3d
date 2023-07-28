/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:23:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:20:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_color	get_color(const char *line);

bool	is_color(const char *line, enum e_color *out_color_id)
{
	if (ft_strncmp(line, "F ", ft_strlen("F ")) == 0)
	{
		*out_color_id = FLOOR;
		return (true);
	}
	if (ft_strncmp(line, "C ", ft_strlen("C ")) == 0)
	{
		*out_color_id = CEILING;
		return (true);
	}
	return (false);
}

void	set_color(t_color *const color, const char *line)
{
	_assert(*color == 0, "Duplicated color\n");
	*color = get_color(line);
}

static t_color	get_color(const char *line)
{
	char **const	rgb = ft_split(line, ',');
	int				i;
	int				num;
	t_color			color;

	_assert(rgb != NULL, "malloc() failed\n");
	i = 0;
	color = 0;
	while (i < 3 && rgb[i] != NULL)
	{
		num = _atoi(rgb[i]);
		_assert(0 <= num && num <= 255, "color is not in range 0 ~ 255\n");
		color = (color << __CHAR_BIT__) | num;
		free(rgb[i]);
		++i;
	}
	_assert(i == 3, "color channel is smaller than 3\n");
	_assert(rgb[3] == NULL, "color channel is larger than 3\n");
	free(rgb);
	return (color);
}
