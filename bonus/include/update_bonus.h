/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:20:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 06:06:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_BONUS_H
# define UPDATE_BONUS_H

# include "game_bonus.h"

# define MARGIN		16
# define MV_SPEED	8.0f
# define RT_SPEED	0.05f

bool	update(t_game *const game, const t_key *const key);

#endif // __UPDATE_BONUS_H__
