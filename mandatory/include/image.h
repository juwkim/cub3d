/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 03:34:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "cub3d.h"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_image;

bool	image_init(t_image *const img, void *mlx, int width, int height);
bool	image_init_by_xpm_file(t_image *const img, void *mlx, char *xpm_file);
void	image_destroy(const t_image *const img, void *mlx);

#endif // __IMAGE_H__
