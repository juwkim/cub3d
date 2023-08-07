/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 00:08:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_init(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (*map == NULL)
		return (false);
	(*map)->list = malloc(sizeof(t_list));
	if ((*map)->list == NULL)
		return (false);
	list_init((*map)->list);
	(*map)->width = 0;
	(*map)->height = 0;
	return (true);
}
