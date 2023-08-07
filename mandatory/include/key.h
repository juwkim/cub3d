/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:01:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 23:56:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "cub3d.h"

bool	key_init(t_key **key);
void	key_destroy(t_key *key);
int		key_press(const int keycode, t_key *const key);
int		key_release(const int keycode, t_key *const key);

#endif // __KEY_H__
