/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:50:07 by angassin          #+#    #+#             */
/*   Updated: 2023/03/08 10:19:37 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	move_allowed(t_program *game, int map_x, int map_y);

/*
	Movement of the sprite according to user input :
	1. determines the new position of the sprite according to the key pressed
	2. 
	3. displays the new image
*/
int	ft_input(int key, t_program *game)
{
	int			map_x;
	int			map_y;

	map_x = game->sprite_position.y / IMG_SCALE;
	map_y = game->sprite_position.x / IMG_SCALE;
	if (key == esc)
		ft_close(game);
	if ((key == w || key == up) && move_allowed(game, map_x - 1, map_y))
	{
		ft_update(game, map_x - 1, map_y);
		game->sprite_position.y -= game->sprite.size.y;
	}
	if ((key == a || key == left) && move_allowed(game, map_x, map_y - 1))
	{	
		ft_update(game, map_x, map_y - 1);
		game->sprite_position.x -= game->sprite.size.x;
	}
	if ((key == s || key == down) && move_allowed(game, map_x + 1, map_y))
	{
		ft_update(game, map_x + 1, map_y);
		game->sprite_position.y += game->sprite.size.y;
	}
	if ((key == d || key == right) && move_allowed(game, map_x, map_y + 1))
	{
		ft_update(game, map_x, map_y + 1);
		game->sprite_position.x += game->sprite.size.x;
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->sprite.ptr, game->sprite_position.x, game->sprite_position.y);
	return (0);
}

/* 
	Put a tile where the sprite was standing, update the map when an item is 
	taken and when it goes to the door exit if the exit is open
*/
int	ft_update(t_program	*game, int map_x, int map_y)
{
	// int	current_spot_x;
	// int	current_spot_y;

	// current_spot_x = game->sprite_position.y / IMG_SCALE;
	if (game->map[map_x][map_y] == EXIT ) //&& open
	{
			ft_close(game);
			return (1);
	}
	game->nb_mov++;
	ft_printf("nb movements : %d\n", game->nb_mov);
	if (game->map[map_x][map_y] == ITEM)
	{
		game->map[map_x][map_y] = TILE;
		game->tile_position.x = map_y * IMG_SCALE;
		game->tile_position.y = map_x * IMG_SCALE;
		action(game);
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->tile.ptr, game->sprite_position.x,
		game->sprite_position.y);
	
	//static	int	frame;
	return (0);
}

/* displays tile instead of item taken, open the door if no items */
void	action(t_program *game)
{
	t_image	blue;

	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->tile.ptr, game->tile_position.x, game->tile_position.y);
	game->nb_items--;
	ft_printf("items left : %d\n", game->nb_items);
	if (game->nb_items == 0)
	{
		game->exit_open = true;
		blue = ft_new_sprite(game->mlx, "sprites/blue_96.xpm");
		mlx_put_image_to_window(game->mlx, game->window.ptr, blue.ptr,
			game->exit_position.x, game->exit_position.y);
		game->exit = ft_new_sprite(game->mlx, "sprites/door_fullyopen_96.xpm");
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->exit.ptr,
			game->exit_position.x, game->exit_position.y);
	}
}

bool	move_allowed(t_program *game, int map_x, int map_y)
{
	if (game->map[map_x][map_y] == WALL)
		return (false);
	if (game->map[map_x][map_y] == EXIT && game->exit_open == false)
	{	
		ft_printf("exit_open : %d\n", game->exit_open);
		return (false);
	}
	return (true);
}
