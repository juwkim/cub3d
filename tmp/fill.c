/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:12:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:20:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_south(t_pixel *const *const data, int i, int j, enum e_texture tex)
{
	int	off;

	off = TEX_WIDTH - 1;
	while (off >= 0)
	{
		data[i][j].tex_id = tex;
		data[i][j].off = off;
		++j;
		--off;
	}
}

void	fill_east(t_pixel *const *const data, int i, int j, enum e_texture tex)
{
	int	off;

	off = 0;
	while (off < TEX_HEIGHT)
	{
		data[i][j].tex_id = tex;
		data[i][j].off = off;
		++i;
		++off;
	}
}

void	fill_north(t_pixel *const *const data, int i, int j, enum e_texture tex)
{
	int	off;

	off = 0;
	while (off < TEX_WIDTH)
	{
		data[i][j].tex_id = tex;
		data[i][j].off = off;
		++j;
		++off;
	}
}

void	fill_west(t_pixel *const *const data, int i, int j, enum e_texture tex)
{
	int	off;

	off = TEX_HEIGHT - 1;
	while (off >= 0)
	{
		data[i][j].tex_id = tex;
		data[i][j].off = off;
		++i;
		--off;
	}
}
