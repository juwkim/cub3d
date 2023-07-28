/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:20:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:01:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cub3d.h"

typedef struct s_window
{
	void	*ptr;
	char	*title;
	int		width;
	int		height;
	t_image	*img;
}	t_window;

bool	window_init(t_window *const win, void *mlx);
void	window_destroy(const t_window *const win, void *mlx);

#endif // __WINDOW_H__
