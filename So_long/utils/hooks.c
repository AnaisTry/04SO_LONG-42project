/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:50:07 by angassin          #+#    #+#             */
/*   Updated: 2023/03/08 23:10:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_update(t_program *game, int map_x, int map_y);
static void	action(t_program *game);
static bool	move_allowed(t_program *game, int map_x, int map_y);
static void	key_pressed(int key, t_program *game, int map_x, int map_y);

/* Movement of the sprite according to user input */
int	ft_input(int key, t_program *game)
{
	int			map_x;
	int			map_y;

	map_x = game->sprite_pos.y / IMG_SCALE;
	map_y = game->sprite_pos.x / IMG_SCALE;
	key_pressed(key, game, map_x, map_y);
	return (0);
}

/* 
	Interactions with the keyboard
	1. determines the new pos of the sprite according to the key pressed
	2. update the elements accordingly
	3. displays the new image of the player
*/
static void	key_pressed(int key, t_program *game, int map_x, int map_y)
{
	if (key == ESC)
		ft_close(game);
	if ((key == w || key == UP) && move_allowed(game, map_x - 1, map_y))
	{
		ft_update(game, map_x - 1, map_y);
		game->sprite_pos.y -= game->sprite.size.y;
	}
	if ((key == a || key == LEFT) && move_allowed(game, map_x, map_y - 1))
	{	
		ft_update(game, map_x, map_y - 1);
		game->sprite_pos.x -= game->sprite.size.x;
	}
	if ((key == s || key == DOWN) && move_allowed(game, map_x + 1, map_y))
	{
		ft_update(game, map_x + 1, map_y);
		game->sprite_pos.y += game->sprite.size.y;
	}
	if ((key == d || key == RIGHT) && move_allowed(game, map_x, map_y + 1))
	{
		ft_update(game, map_x, map_y + 1);
		game->sprite_pos.x += game->sprite.size.x;
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->sprite.ptr, game->sprite_pos.x, game->sprite_pos.y);
}

/* 
	Put a tile where the sprite was standing, update the map when an item is 
	taken and exit the game if the player enter the open exit
*/
//static	int	frame;
static int	ft_update(t_program	*game, int map_x, int map_y)
{
	if (game->elements.map[map_x][map_y] == EXIT)
	{
		ft_close(game);
		return (1);
	}
	game->nb_mov++;
	ft_printf("nb movements : %d\n", game->nb_mov);
	if (game->elements.map[map_x][map_y] == ITEM)
	{
		game->elements.map[map_x][map_y] = TILE;
		game->tile_pos.x = map_y * IMG_SCALE;
		game->tile_pos.y = map_x * IMG_SCALE;
		action(game);
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->tile.ptr, game->sprite_pos.x, game->sprite_pos.y);
	return (0);
}

/* displays tile instead of item taken, open the door if no items */
static void	action(t_program *game)
{
	t_image	blue;

	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->tile.ptr, game->tile_pos.x, game->tile_pos.y);
	game->nb_items--;
	ft_printf("items left : %d\n", game->nb_items);
	if (game->nb_items == 0)
	{
		game->exit_open = true;
		blue = ft_new_sprite(game->mlx, "sprites/blue_96.xpm");
		mlx_put_image_to_window(game->mlx, game->window.ptr, blue.ptr,
			game->exit_pos.x, game->exit_pos.y);
		game->exit = ft_new_sprite(game->mlx, "sprites/door_fullyopen_96.xpm");
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->exit.ptr,
			game->exit_pos.x, game->exit_pos.y);
	}
}

static bool	move_allowed(t_program *game, int map_x, int map_y)
{
	if (game->elements.map[map_x][map_y] == WALL)
		return (false);
	if (game->elements.map[map_x][map_y] == EXIT && game->exit_open == false)
	{	
		ft_printf("exit_open : %d\n", game->exit_open);
		return (false);
	}
	return (true);
}
