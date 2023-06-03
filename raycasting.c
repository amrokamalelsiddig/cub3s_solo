/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:24:50 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/06/03 21:09:11 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define Total_ray 60 


void init_ray(t_cub *cub)
{
	cub->raycasting = malloc(sizeof(t_ray) * Total_ray);
	if (!cub->raycasting)
		perror("malloc failed \n");
	int i = 0;
	float con;

	while(i < Total_ray)
	{
		printf("value of %d\n",i);
		cub->raycasting[i].index = i;
		cub->raycasting[i].data = 0;
		cub->raycasting[i].ray_x = 0;
		cub->raycasting[i].ray_y = 0;
		cub->raycasting[i].Hit_it = 0;
		if (i == 0)
		{
			printf("THIS %f\n",cub->player->rot_ang );
			cub->raycasting[i].angle = (float)cub->player->rot_ang - (float)(cub->player->FOV / 2);
			printf("1 -> %f\n",cub->raycasting[i].angle);
		}
		else if (i > 0)
		{
			cub->raycasting[i].angle = con + ((float)cub->player->FOV / (float)Total_ray);
			printf("%d-> %f\n",i,cub->raycasting[i].angle);
		}
		con = cub->raycasting[i].angle;
		printf("%f\n",con);
		i++;
	}
}


void cast_rays(t_cub *cub)
{
	int i = 1;
	int j = 0;
	init_ray(cub);
	printf("cast ray\n");
	while(i < Total_ray)
	{
		j = 300;
		cub->raycasting[i].ray_x = cub->player->x + cos(cub->raycasting[i ].angle) * j;
		cub->raycasting[i].ray_y = cub->player->y + sin(cub->raycasting[i ].angle) * j;

		while(j > 0)
		{
			cub->raycasting[i].ray_x = cub->player->x + cos(cub->raycasting[i].angle) * j;
			cub->raycasting[i].ray_y = cub->player->y + sin(cub->raycasting[i].angle) * j;
			mlx_pixel_put(cub->mlx, cub->win,cub->raycasting[i].ray_x, cub->raycasting[i].ray_y,COLOR2);
			j--;
		}
		i++;
	}
}