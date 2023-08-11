/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:20:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 05:32:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cub3d.h"
# include "image.h"

bool	window_init(t_window *const win, t_texture *const tex, void *mlx);
void	window_destroy(const t_window *const win, void *mlx);
void	window_render_background(t_window *const win);
void	window_texture_print(t_window *const win);

#endif // __WINDOW_H__
