/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:22:19 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/05/31 18:24:02 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void reset(t_cub *cub, int key)
{
	if (key == 119 || key == 25 || key == 97 || key == 38)
		cub->player->walk_dir = 0;
	if (key == 0 || key ==  65361 || key == 2 || key == 65363 )
		cub->player->side_flag = 0;
}

int		joystick(int c, t_cub *cub)
{
	clear_screen();
	if (c == 13 || c == 65362)
	{
		printf("up arrow\n");
		printf("no action\n");
	}
	else if (c == 1 || c == 65364)
	{
		printf("down arrow\n");
		printf("no action\n");
		// cub->player->walk_dir = -1;
	}
	else if (c == 0 || c ==  65361)
	{
		printf("left arrow\n");
		cub->player->side_flag = -1;
		cub->player->rot_ang += cub->player->side_flag * cub->player->rot_speed;
	}
	else if (c == 2 || c == 65363 )
	{
		printf("right arrow\n");
		cub->player->side_flag = 1;
		cub->player->rot_ang += cub->player->side_flag * cub->player->rot_speed;
		// rotate_right(cub);
	}
	else if (c == 119 || c == 25) // w
	{
		printf("w\n");
		cub->player->walk_dir = 1;	
	}
	else if (c == 97 || c == 38) // a
	{
		printf("a\n");
		cub->player->walk_dir = -1;
	}
	else if (c == 115 || c == 39)
	{
		printf("s\n");
	}
	else if (c == 100 || c == 40)
	{
		printf("d\n");
	}
	else if (c == 53 || c == 99 || c == 65307)
		exit(1);
	// print_grid(cub);
	render(cub);
	reset(cub, c);
	return (0);
}