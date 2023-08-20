/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:59:44 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

bool	is_extension(const char *filename, const char *extension)
{
	const size_t	file_len = ft_strlen(filename);
	const size_t	extension_len = ft_strlen(extension);

	return (file_len > extension_len && \
		ft_strcmp(filename + file_len - extension_len, extension) == 0);
}
