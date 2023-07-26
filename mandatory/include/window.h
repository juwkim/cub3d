/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:20:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:49:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "main.h"
# include "image.h"

void	window_init(const t_cub3d *const cub3d, t_window *const win);
void	window_destroy(const t_cub3d *const cub3d, t_window *const win);

#endif // __WINDOW_H__
