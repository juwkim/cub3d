/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:01:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 03:34:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "cub3d.h"

# ifdef __linux__

enum e_key
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_RELESE = 255
};

# else

enum e_key
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_RELESED = 255
};
# endif // __linux__

typedef struct s_key
{
	enum e_key	vertical;
	enum e_key	horizontal;
	enum e_key	rotation;
	bool		esc;
}	t_key;

bool	key_init(t_key *const key);
void	key_destroy(const t_key *const key);
int		key_press(const int keycode, t_key *const key);
int		key_release(const int keycode, t_key *const key);

#endif // __KEY_H__
