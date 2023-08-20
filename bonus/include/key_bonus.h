/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:01:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:45:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BONUS_H
# define KEY_BONUS_H

# include "cub3d_bonus.h"

bool	key_init(t_key *const key, const double rotation_speed, \
	const double moving_speed);
void	key_destroy(const t_key *const key);
int		key_press(const int keycode, t_cub3d *const cub3d);
int		key_release(const int keycode, t_key *const key);

#endif // __KEY_BONUS_H__
