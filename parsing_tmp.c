/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:24:35 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/05/31 19:23:55 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void nose(t_cub *cub)
// {
// 	int i = 20;
	
// 	while(i > 0)
// 	{
// 		mlx_pixel_put(cub->mlx, cub->win,
// 		 cub->player->x, cub->player->y- i,COLOR);
// 		i--;
// 	}

// }


#include <math.h>

void render_nose(t_cub *cub)
{

	cub->player->nose_x = cub->player->x + cos(cub->player->rot_ang) * cub->player->nose_l ;
	cub->player->nose_y = cub->player->y + sin(cub->player->rot_ang) * cub->player->nose_l ;
	// printf("value of x %d\n",cub->player->x);
	// printf("value of y %d\n",cub->player->y);
	// printf("value of nose_x %i\n",cub->player->nose_x);
	// printf("value of nose_y %i\n",cub->player->nose_y);
	int i = cub->player->nose_l;

	while(i > 0)
	{
		cub->player->nose_x = cub->player->x + cos(cub->player->rot_ang) * i;
		cub->player->nose_y = cub->player->y + sin(cub->player->rot_ang) * i ;
		mlx_pixel_put(cub->mlx, cub->win,
		 cub->player->nose_x, cub->player->nose_y,COLOR);
		i--;
	}
}

void render_circle(t_cub *cub, int c_x, int c_y, int radius)
{
	int x = radius;
	int y = 0;
	int radius_error = 1 - x;
	while (x >= y)
	{
		mlx_pixel_put(cub->mlx, cub->win, c_x + x, c_y + y, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x + y, c_y + x, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x - y, c_y + x, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x - x, c_y + y, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x - x, c_y - y, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x - y, c_y - x, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x + y, c_y - x, COLOR);
		mlx_pixel_put(cub->mlx, cub->win, c_x + x, c_y - y, COLOR);
		y++;
		if (radius_error < 0)
			radius_error += 2 * y + 1;
		else
		{
			x--;
			radius_error += 2 * (y - x + 1);
		}
	}
	render_nose(cub);
}

void create_grid(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// printf("1 - value of x %i\n",cub->tmp->x);
	// printf("2 - value of y %i\n",cub->tmp->y);
	cub->map->grid = malloc(sizeof(char *) * cub->map->y);
	while (j < cub->map->y)
	{
		cub->map->grid[j] = malloc(sizeof(char) * cub->map->x);
		i = 0;
		while (i < cub->map->x)
		{
			cub->map->grid[j][i] = '0';
			i++;
		}
		j++;
	}
}

void print_grid(t_cub *cub)
{
	int i;
	int j;
	// printf("value of x %i\n",cub->map->x);
	// printf("value of y %i\n",cub->map->y);ad

	i = 0;
	j = 0;
	while(j < cub->map->y)
	{
		i = 0;
		while(i < cub->map->x)
		{
			printf("%c", cub->map->grid[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}


void fill_grid(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(j < cub->map->y)
	{
		i = 0;
		while(i < cub->map->x)
		{
			if (i == 0 || i == cub->map->x - 1 || j == 0 || j == cub->map->y - 1)
				cub->map->grid[j][i] = '1';
			i++;
		}
		j++;
	}
	// printf("value of pos %i\n",cub->playerPos->y);
	// printf("value of pos %i\n",cub->playerPos->x);
}

void init(t_cub *cub, char **av)
{
	cub->mlx = mlx_init();
	cub->img_h = 32;
	cub->img_w = 32;
	cub->map = malloc(sizeof(t_map));
	cub->map->x = atoi(av[1]);
	cub->map->y = atoi(av[2]);
	cub->map->size = cub->map->y * cub->map->x;
	cub->wall = mlx_xpm_file_to_image(cub->mlx,"xmp_file/output-onlinepngtools_1_.xpm",&cub->img_w,&cub->img_w);
	cub->floor = mlx_xpm_file_to_image(cub->mlx,"xmp_file/output-onlinepngtools.xpm",&cub->img_w,&cub->img_w);	
	create_grid(cub);
	fill_grid(cub);
	print_grid(cub);
	// init_player(cub);
	cub->player = malloc(sizeof(t_player));
	cub->player->x = (cub->map->x*16/2);
	cub->player->y = (cub->map->y*16/2);
	cub->player->walk_dir = 0;
	cub->player->side_flag = 0;
	cub->player->speed = 10.0;
	cub->player->rot_speed = 10.0 * (PI/180);
	cub->player->rot_ang =  PI/2;
	cub->player->speed = 5;
	cub->player->step = 0;

	// cub->player->nose = cu b->map->size / 50;
	// cub->player->nose_x = cub->player->x ;
	// cub->player->nose_y = cub->player->y -10;
	cub->player->nose_l = 30;

}

void render(t_cub *cub)
{
	int i;
	int j;
	int meter;

	i = 0;
	j = 0;
	meter = 0;
	while (i < cub->map->y)
	{
		while (j < cub->map->x)
		{
			if (cub->map->grid[i][j] == '1')
				mlx_put_image_to_window(cub->mlx, cub->win, cub->wall, (16 * j), (16 * i));
			else if (cub->map->grid[i][j] == '0')
				mlx_put_image_to_window(cub->mlx, cub->win, cub->floor, (16 * j), (16 * i));
			j++;
		}
		j = 0;
		i++;
	}
	render_circle(cub,cub->player->x,cub->player->y,cub->map->size / 150 );
	mlx_string_put(cub->mlx,cub->win, 20, 30,000000,ft_strjoin("X   : ",ft_itoa(cub->player->x)));
	mlx_string_put(cub->mlx,cub->win, 20, 40,000000,ft_strjoin("Y   : ",ft_itoa(cub->player->y)));
	mlx_string_put(cub->mlx,cub->win, 20, 50,000000,ft_strjoin("X_N : ",ft_itoa(cub->player->nose_x)));
	mlx_string_put(cub->mlx,cub->win, 20, 60,000000,ft_strjoin("Y_N : ",ft_itoa(cub->player->nose_y)));
}
