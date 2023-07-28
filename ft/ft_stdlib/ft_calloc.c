/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 02:03:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 17:45:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/**
 * @brief 
 * Allocates memory for an array of nmemb elements of size bytes each.
 * The memory is set to zero.
 * @param nmemb 
 * @param size 
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;

	buf = malloc(nmemb * size);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, nmemb * size);
	return (buf);
}
