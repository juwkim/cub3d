/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:01:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "config.h"

# define LR	0.5f

void	raycasting(t_config *const config, double lookat, t_texture *tex);

#endif // __RAYCASTING_H__