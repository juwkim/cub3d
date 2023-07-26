/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:59:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 03:28:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "main.h"

bool	cub3d_init(t_cub3d *const cub3d, const char *filename);
int		cub3d_destroy(t_cub3d *const cub3d);
int		cub3d_play(t_cub3d *const cub3d);
void	cub3d_render(t_cub3d *const cub3d);
bool	cub3d_update(t_cub3d *const cub3d);

#endif // __CUB3D_H__
