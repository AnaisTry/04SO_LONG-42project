/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:34:59 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 17:04:27 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*									[Includes]								*/

// minilibX
# include "../../mlx/mlx.h"
//# include <mlx.h>
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
// bool
# include <stdbool.h> 
// libft
# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/includes/get_next_line.h"

/*									[Macros]								*/

# define MAP_EXT ".ber"
# define IMG_SCALE 96
# define VALID_CHARS "01CEP"
# define CHECKED 'X'
// events
# define DESTROY_NOTIFY 17
# define MASK 0

/*									[Typedefs]								*/

// map elements
typedef enum e_elements
{
	TILE = '0',
	WALL = '1',
	PLAYER = 'P',
	ITEM = 'C',
	EXIT = 'E'
}			t_elements;

// keyboard
typedef enum e_keys
{
	ESC = 53,
	a = 0,
	s,
	d,
	w = 13,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP
}			t_keys;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_map
{
	char		**map;
	t_elements	type;
	t_vector	pos;
	int			check_items;
	bool		check_exit;
}				t_map;

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
	t_map		elements;
	t_window	window;
	t_image		wall;
	t_image		sprite;
	t_vector	sprite_pos;
	t_image		item;
	t_image		tile;
	t_image		exit;
	t_vector	exit_pos;
	t_vector	elem_pos;
	int			nb_mov;
	int			nb_items;
	bool		exit_open;
}				t_program;

/* 									[src] 									*/

// read_map.c
void		check_map(char	*argv, t_program *game);

// check_path.c
void		check_path(t_program	*game);

//draw.c
void		draw_map(t_program	*game);

// hook.c
//return value required by mlx_key_hook
int			ft_input(int key, t_program *param);

/* 									[utils] 								*/

// window.c
t_window	ft_new_window(t_program *game, int width, int height, char *name);
int			ft_close(t_program *game);

// image.c
t_image		ft_new_sprite(t_program *game, char *path);
t_image		ft_new_image(t_program *game, int width, int height);

// errors.c
void		error_exit(char *err_message, t_program *game);

// utils.c
int			map_height(char	**map);
int			count_elements(t_program *game, char type);
void		*free_array(char **arr);
void		destroy_images(t_program *game);

#endif
