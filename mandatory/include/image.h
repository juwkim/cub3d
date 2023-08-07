/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 00:01:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "cub3d.h"

bool	image_init(t_image **img, void *mlx, int width, int height);
bool	image_init_by_xpm_file(t_image **img, void *mlx, char *xpm_file);
void	image_destroy(t_image *img, void *mlx);

#endif // __IMAGE_H__
