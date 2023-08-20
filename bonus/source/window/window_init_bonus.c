/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:17:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:44:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

static void	window_init_background(t_window *const win, \
	const t_texture *const tex);

bool	window_init(t_window *const win, t_texture *const tex, void *mlx)
{
	int	i;

	win->ptr = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (win->ptr == NULL)
		return (false);
	if (image_init(&win->img, mlx, WIN_WIDTH, WIN_HEIGHT) == false || \
		image_init(&win->bg, mlx, WIN_WIDTH, WIN_HEIGHT) == false)
		return (false);
	win->tex_id = ft_calloc(WIN_HEIGHT, sizeof(enum e_texture *));
	win->door_idx = ft_calloc(WIN_HEIGHT, sizeof(int *));
	if (win->tex_id == NULL || win->door_idx == NULL)
		return (false);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		win->tex_id[i] = malloc(sizeof(enum e_texture) * WIN_WIDTH);
		win->door_idx[i] = malloc(sizeof(int) * WIN_WIDTH);
		if (win->tex_id[i] == NULL || win->door_idx[i] == NULL)
			return (false);
		++i;
	}
	win->width = WIN_WIDTH;
	win->height = WIN_HEIGHT;
	window_init_background(win, tex);
	return (true);
}

static void	window_init_background(t_window *const win, \
	const t_texture *const tex)
{
	int		i;
	int		j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT / 2)
		{
			*image_address(&win->bg, i, j) = tex->bgcolor[T_CEILING - N_BGPAD];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			*image_address(&win->bg, i, j) = tex->bgcolor[T_FLOOR - N_BGPAD];
			++i;
		}
		++j;
	}
}
