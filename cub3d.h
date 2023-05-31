/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:02:13 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/05/31 18:13:53 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include  "mlx_linux/mlx.h"
# include  "minilibx-linux/mlx.h"


#define  PI  3.1415926535

// setting the keys vaules 
# define K_ESC      9    // XK_Escape
# define K_W        25   // XK_w
# define K_A        38   // XK_a
# define K_S        39   // XK_s
# define K_D        40   // XK_d
# define K_LEFT     113  // XK_Left
# define K_RIGHT    114  // XK_Right
# define K_UP       111  // XK_Up
# define K_DOWN     116  // XK_Down
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_release		3
# define X_EVENT_KEY_EXIT			17 //exit key code
# define COLOR 						0x00FF0000

typedef struct map
{
	unsigned int 	x;
	unsigned int	y;
	char 			**grid;
	int 			size;
}	t_map;

typedef struct player
{
	int	x;
	int	y;
	int	nose_x;
	int	nose_y;
	int nose_l;
	int delta_x;
	int delta_y;
	float	speed;  // moving speed 
	float	rot_speed;  // rotate speed 
	float	rot_ang;
	int 	side_flag; // 1 for right , -1 for left 
	int 	walk_dir; // 1 forword , -1 backword 
} t_player;

typedef struct cub
{	
	void	*mlx;
	void 	*win;
	void	*wall;
	void 	*floor;
	int		img_h;
	int 	img_w;
	t_player *player;
	t_map *map;
} t_cub;


int		joystick(int c, t_cub *cub);


void render(t_cub *cub);
void create_grid(t_cub *cub);
void print_grid(t_cub *cub);
void fill_grid(t_cub *cub);
void init(t_cub *cub, char **av);
void clear_screen();
void render_nose(t_cub *cub);
void rotate_right(t_cub *cub);
char	*ft_itoa(int n);
static int	ft_nbrlen(int nbr);
char	*ft_strdup(const char	*s1);
size_t	ft_strlen(const char *s);
static char	*ft_reverse(char *src);
static char	*ft_handle(int z);

#endif