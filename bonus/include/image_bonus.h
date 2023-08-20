/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:45:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_BONUS_H
# define IMAGE_BONUS_H

# include "cub3d_bonus.h"

bool	image_init(t_image *const img, void *mlx, int width, int height);
bool	image_init_by_xpm_file(t_image *const img, void *mlx, char *xpm_file);
void	image_destroy(const t_image *const img, void *mlx);
t_color	*image_address(const t_image *const img, const int i, const int j);

#endif // __IMAGE_BONUS_H__
