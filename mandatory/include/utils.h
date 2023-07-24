/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:08:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:01:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "config.h"

# include <sys/errno.h>	// To use errno

bool	is_extension(const char *filename, const char *extension);
void	_assert(bool expr, const char *str);
int		_atoi(const char *nptr);
int		_strfind(const char *s, char c);
void	print_map(const t_map *const map);

#endif // __UTILS_H__
