/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:20:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 23:56:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cub3d.h"
# include "image.h"

bool	window_init(t_window **win, void *mlx);
void	window_destroy(t_window *win, void *mlx);

#endif // __WINDOW_H__
