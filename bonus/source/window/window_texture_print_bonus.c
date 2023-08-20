/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_texture_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:27:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:44:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void	window_texture_print(t_window *const win, const int x, const int y)
{
	if (x < 0 || x >= win->width)
		return ;
	if (y < 0 || y >= win->height)
		return ;
	if (win->tex_id[y][x] == T_SOUTH)
		printf("(%d, %d) SOUTH\n", x, y);
	else if (win->tex_id[y][x] == T_EAST)
		printf("(%d, %d) EAST\n", x, y);
	else if (win->tex_id[y][x] == T_NORTH)
		printf("(%d, %d) NORTH\n", x, y);
	else if (win->tex_id[y][x] == T_WEST)
		printf("(%d, %d) WEST\n", x, y);
	else if (win->tex_id[y][x] == T_DOOR)
		printf("(%d, %d) DOOR\n", x, y);
	else if (win->tex_id[y][x] == T_ITEM)
		printf("(%d, %d) ITEM\n", x, y);
	else if (win->tex_id[y][x] == T_FLOOR)
		printf("(%d, %d) FLOOR\n", x, y);
	else if (win->tex_id[y][x] == T_CEILING)
		printf("(%d, %d) CEILING\n", x, y);
}
