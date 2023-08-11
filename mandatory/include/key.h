/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:01:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:42:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "cub3d.h"

bool	key_init(t_key *const key, const double rotation_speed, \
	const double moving_speed);
void	key_destroy(const t_key *const key);
int		key_press(const int keycode, t_key *const key);
int		key_release(const int keycode, t_key *const key);

#endif // __KEY_H__
