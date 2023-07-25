/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:08:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 23:27:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "config.h"
# include <sys/errno.h>

void	_assert(const bool expr, const char *const str);
int		_atoi(const char *nptr);
bool	is_extension(const char *filename, const char *extension);

#endif // __UTILS_H__
