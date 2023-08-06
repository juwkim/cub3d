/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:48:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:21:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	trim_upper(t_pixel **const data, const int i, const int j);
static void	trim_lower(t_pixel **const data, const int i, const int j);

void	trim_map(t_map *const rmap)
{
	int	i;
	int	j;

	i = 0;
	while (i < rmap->height)
	{
		j = 0;
		while (j < rmap->width)
		{
			if (rmap->data[i][j].tex_id <= WEST)
			{
				if (i > 0)
					trim_upper(rmap->data, i, j);
				if (i + TEX_HEIGHT < rmap->height)
					trim_lower(rmap->data, i, j);
			}
			j += TEX_WIDTH;
		}
		i += TEX_HEIGHT;
	}
}

static void	trim_upper(t_pixel **const data, const int i, const int j)
{
	if (data[i - 1][j].tex_id == SPACE)
	{
		data[i][j].tex_id = SOUTH;
		data[i][j + TEX_WIDTH - 1].tex_id = SOUTH;
	}
	else
	{
		data[i][j].tex_id = EAST;
		data[i][j + TEX_WIDTH - 1].tex_id = WEST;
	}
}

static void	trim_lower(t_pixel **const data, const int i, const int j)
{
	if (data[i + TEX_HEIGHT][j].tex_id == SPACE)
	{
		data[i + TEX_HEIGHT - 1][j].tex_id = NORTH;
		data[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1].tex_id = NORTH;
	}
	else
	{
		data[i + TEX_HEIGHT - 1][j].tex_id = EAST;
		data[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1].tex_id = WEST;
	}
}
