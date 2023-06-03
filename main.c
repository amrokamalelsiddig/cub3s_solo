/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:03:36 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/06/03 18:51:06 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_screen() {
	system("clear");
}

int main(int ac, char **av)
{
	(void)ac;
	if (!av[1] || !av[2])
	{
		perror("invaild");
		exit(1);
	}
	t_cub cub;

	init(&cub,av);
	cub.win = mlx_new_window(cub.mlx, (16 * cub.map->x), (16 * cub.map->y), "Hello world!");
	// cub.img = mlx_get_data_addr(cub.mlx,&cub.bits_per_pixel,&cub.size_line,&cub.endian);
	// printf("Bits per pixel: %d\n",cub.bits_per_pixel);
    // printf("Size of each line: %d\n",cub.size_line);
    // printf("Endianness: %d\n",cub.endian);
	render(&cub);
	mlx_key_hook(cub.win, joystick, &cub);
	// mlx_hook(cub.win, 2, 0,joystick, &cub);
	mlx_loop(cub.mlx);
	return 0;
}