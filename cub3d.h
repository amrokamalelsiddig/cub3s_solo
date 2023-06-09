/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:02:13 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/06/03 20:10:10 by aelsiddi         ###   ########.fr       */
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
# include <stdbool.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include "libft/libft.h"
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
# define COLOR2 					0x00FF00


typedef struct raycasting
{
	int					index;
	int 				data;
	float 				angle;
	int  				ray_x;
	int				ray_y;
	bool 				Hit_it;
} t_ray;


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
	int     step;
	int 	FOV;
} t_player;

typedef struct cub
{	
	void	*mlx;
	void 	*win;
	void 	*img;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;
	void	*wall;
	void 	*floor;
	int		img_h;
	int 	img_w;
	t_map *map;
	t_player *player;
	/// 3d part;
	void	*mlx2;
	void 	*win2;
	void 	*img2;
	int 	strip_w;
	t_ray *raycasting;
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


// Libft to be removed 
char	*ft_itoa(int n);
static int	ft_nbrlen(int nbr);
char	*ft_strdup(const char	*s1);
size_t	ft_strlen(const char *s);
static char	*ft_reverse(char *src);
static char	*ft_handle(int z);
char	*ft_strjoin(char const *s1, char const	*s2);
void	*ft_calloc(size_t	count, size_t size);
void	ft_bzero(void	*s,	size_t	n);


//ray cast 
void cast_rays(t_cub *cub);

#endif