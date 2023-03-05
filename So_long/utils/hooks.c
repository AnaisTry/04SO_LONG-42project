/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:50:07 by angassin          #+#    #+#             */
/*   Updated: 2023/03/05 19:22:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	Movement of the sprite according to user input :
	1. determines the new position of the sprite according to the key pressed
	
	3. displays the new image
*/
int	ft_input(int key, void *param)
{
	t_program	*game;
	int			map_x;
	int			map_y;

	game = (t_program *)param;
	map_x = game->sprite_position.y / IMG_SCALE;
	map_y = game->sprite_position.x / IMG_SCALE;
	ft_printf("map_x %d, map_y %d\n", map_x, map_y);
	//mlx_clear_window(game->mlx, game->window.ptr);
	if (key == esc)
		ft_close(game);
	if ((key == w || key == up) && (game->map[map_x - 1][map_y] != WALL))
	{
		ft_update(game);
		game->sprite_position.y -= game->sprite.size.y;
	}
	if ((key == a || key == left) && (game->map[map_x][map_y - 1] != WALL))
	{	
		ft_update(game);
		game->sprite_position.x -= game->sprite.size.x;
	}
	if ((key == s || key == down) && (game->map[map_x + 1][map_y] != WALL))
	{
		ft_update(game);
		game->sprite_position.y += game->sprite.size.y;
	}
	if ((key == d || key == right) && (game->map[map_x][map_y + 1] != WALL))
	{
		ft_update(game);
		game->sprite_position.x += game->sprite.size.x;
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->sprite.ptr, game->sprite_position.x, game->sprite_position.y);
	
	// print the key pressed so you know the number of each key
	ft_printf("Key pressed -> %d\n", key);
	return (0);
}

/* Put a tile where the sprite was standing */
int	ft_update(void	*param)
{
	t_program	*game;

	game = (t_program *)param;
	mlx_put_image_to_window(game->mlx, game->window.ptr,
			game->tile.ptr, game->sprite_position.x,
			game->sprite_position.y);
	//static	int	frame;
	// mlx_put_image_to_window(game->mlx, game->window.ptr, game->item.ptr,
	// 	game->item_position.x, game->item_position.y);
	// mlx_put_image_to_window(game->mlx, game->window.ptr, game->tile.ptr,
	// 							game->tile_position.x, game->tile_position.y);
	return (0);
}

// void	moving_rules(t_program	*game)
// {

// }