/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:23:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	if (argc != 2)
	{
		printf("Usage: ./cub3D *.cub\n");
		return (EXIT_FAILURE);
	}
	if (cub3d_init(&cub3d, argv[1]) == false)
		return (EXIT_FAILURE);
	return (mlx_loop(cub3d.mlx));
}
