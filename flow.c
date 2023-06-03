/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:22:19 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/06/03 20:13:44 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief reset the value to zero so it will not effect the next move 
/// @param t_cub  
/// @param key pressed key on the keyboard 
void reset(t_cub *cub, int key)
{
	if (key == 119 || key == 25 || key == 97 || key == 38)
	{
		cub->player->walk_dir = 0;
		cub->player->step = 0;
	}
	if (key == 0 || key ==  65361 || key == 2 || key == 65363 )
		cub->player->side_flag = 0;
}
/// @brief transalte keys to move within the map // check the block that about to travel is vaild or no 
/// @param  t_cub
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
		if(cub->map->grid[(int)(cub->player->y + sin(cub->player->rot_ang) * cub->player->step)/16][(int)(cub->player->x + cos(cub->player->rot_ang) * cub->player->step)/16] != '1')
		{
			printf("value of x %d\n",cub->player->x);
			printf("value of y %d\n",cub->player->y);
			printf("value of nose_x %i\n",cub->player->nose_x);
			printf("value of nose_y %i\n",cub->player->nose_y);
		}
	}
	else if (c == 2 || c == 65363 )
	{
		printf("right arrow\n");
		cub->player->side_flag = 1;
		cub->player->rot_ang += cub->player->side_flag * cub->player->rot_speed;
		if(cub->map->grid[(int)(cub->player->y + sin(cub->player->rot_ang) * cub->player->step)/16][(int)(cub->player->x + cos(cub->player->rot_ang) * cub->player->step)/16] != '1')
		{
			printf("value of x %d\n",cub->player->x);
			printf("value of y %d\n",cub->player->y);
			printf("value of nose_x %i\n",cub->player->nose_x);
			printf("value of nose_y %i\n",cub->player->nose_y);
		}
	}
	else if (c == 119 || c == 25) // w
	{
		printf("w\n");
		cub->player->walk_dir = 1;
		cub->player->step = cub->player->walk_dir * cub->player->speed; 
		if(cub->map->grid[(int)(cub->player->y + sin(cub->player->rot_ang) * cub->player->step)/16][(int)(cub->player->x + cos(cub->player->rot_ang) * cub->player->step)/16] != '1')
		{
			cub->player->x += cos(cub->player->rot_ang) * cub->player->step;
			cub->player->y += sin(cub->player->rot_ang) * cub->player->step;
			printf("value of x %d\n",cub->player->x);
			printf("value of y %d\n",cub->player->y);
			printf("value of nose_x %i\n",cub->player->nose_x);
			printf("value of nose_y %i\n",cub->player->nose_y);
		}
	}
	else if (c == 115 || c == 39)
	{
		printf("s\n");
		cub->player->walk_dir = -1;
		cub->player->step = cub->player->walk_dir * cub->player->speed;
		if(cub->map->grid[(int)(cub->player->y + sin(cub->player->rot_ang) * cub->player->step)/16][(int)(cub->player->x + cos(cub->player->rot_ang) * cub->player->step)/16] != '1')
		{	
			cub->player->x = cub->player->x + cos(cub->player->rot_ang) * cub->player->step;
			cub->player->y = cub->player->y  + sin(cub->player->rot_ang) * cub->player->step;
			printf("value of x %d\n",cub->player->x);
			printf("value of y %d\n",cub->player->y);
			printf("value of nose_x %i\n",cub->player->nose_x);
			printf("value of nose_y %i\n",cub->player->nose_y);
		}
	}
	else if (c == 97 || c == 38) // a
	{
		printf("a\n");
	
	}
	else if (c == 100 || c == 40)
	{
		printf("d\n");
	}
	else if (c == 53 || c == 99 || c == 65307)
		exit(1);
	// print_grid(cub);
	// mlx_destroy_image(cub->mlx,cub->img);
	// cub->img = mlx_new_image(cub->mlx, (16 * cub->map->x), (16 * cub->map->y));
	// cub->img = mlx_get_data_addr(cub->img,\
	// &cub->\
	// ,&cub-> );
	render(cub);	
	reset(cub, c);
	return (0);
}