/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:34:59 by angassin          #+#    #+#             */
/*   Updated: 2023/03/03 18:18:08 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*									[Includes]								*/

// minilibX
# include "../mlx/mlx.h"
// exit
# include <stdlib.h>
// open
# include <fcntl.h>
//close, read
# include <unistd.h>
// strerror
# include <string.h>
// perror
# include <stdio.h>
# include <sys/errno.h>
// libft
# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/includes/get_next_line.h"

/*									[Macros]								*/

# define MAP_EXT ".ber"
# define IMG_SCALE 96

// events
# define DESTROY_NOTIFY 17
# define MASK 0

// map elements
# define TILE '0'
# define WALL '1'
# define PLAYER	'P'
# define ITEM 'C'
# define EXIT 'E'

/*									[Typedefs]								*/

// keyboard
typedef enum e_keys
{
	esc = 53,
	a = 0,
	s,
	d,
	w = 13,
	left = 123,
	right,
	down,
	up
}			t_keys;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window
{
	void		*ptr;
	t_vector	size;
}				t_window;

typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program
{
	void		*mlx;
	char		**map;
	t_window	window;
	t_image		wall;
	t_vector	wall_position;
	t_image		sprite;
	t_vector	sprite_position;
	t_image		item;
	t_vector	item_position;
	t_image		tile;
	t_vector	tile_position;
}				t_program;

/* src */
//draw.c
void		draw_map(t_program	*game);

/* utils */
// window.c
t_window	ft_new_window(t_program game, int width, int height, char *name);
int			ft_close(t_program *game);
// image.c
t_image		ft_new_sprite(void *mlx, char *path);
// hook.c
int			ft_input(int key, void *param);
int			ft_update(void *param);
// read_map.c
void		check_map(char	*argv, t_program *game);

#endif
