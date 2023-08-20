/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:45:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:45:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "cub3d_bonus.h"

bool	is_extension(const char *filename, const char *extension);
double	radian(const int degree);
int		degree(const double radian);

#endif // __UTILS_BONUS_H__
