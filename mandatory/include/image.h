/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:48:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "main.h"

bool	image_init(const t_cub3d *const cub3d, t_image *const img);
void	image_destroy(const t_cub3d *const cub3d, t_image *const img);

#endif // __IMAGE_H__
