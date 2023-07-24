/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:20:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:01:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "config.h"

# define MARGIN		16
# define MV_SPEED	8.0f
# define RT_SPEED	0.05f

bool	update(t_config *const config, const t_key *const key);

#endif // __UPDATE_H__
