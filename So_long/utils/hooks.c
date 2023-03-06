/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:50:07 by angassin          #+#    #+#             */
/*   Updated: 2023/03/06 12:24:33 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	Movement of the sprite according to user input :
	1. determines the new position of the sprite according to the key pressed
	
	3. displays the new image
*/
void	ft_input(int key, t_program *game)
{
	int			map_x;
	int			map_y;

	map_x = game->sprite_position.y / IMG_SCALE;
	map_y = game->sprite_position.x / IMG_SCALE;
	ft_printf("map_x %d, map_y %d\n", map_x, map_y);
	//mlx_clear_window(game->mlx, game->window.ptr);
	if (key == esc)
		ft_close(game);
	if ((key == w || key == up) && (game->map[map_x - 1][map_y] != WALL))
	{
		ft_update(game, map_x - 1, map_y);
		game->sprite_position.y -= game->sprite.size.y;
	}
	if ((key == a || key == left) && (game->map[map_x][map_y - 1] != WALL))
	{	
		ft_update(game, map_x, map_y - 1);
		game->sprite_position.x -= game->sprite.size.x;
	}
	if ((key == s || key == down) && (game->map[map_x + 1][map_y] != WALL))
	{
		ft_update(game, map_x + 1, map_y);
		game->sprite_position.y += game->sprite.size.y;
	}
	if ((key == d || key == right) && (game->map[map_x][map_y + 1] != WALL))
	{
		ft_update(game, map_x, map_y + 1);
		game->sprite_position.x += game->sprite.size.x;
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->sprite.ptr, game->sprite_position.x, game->sprite_position.y);
	
	// print the key pressed so you know the number of each key
	//ft_printf("Key pressed -> %d\n", key);
}

/* Put a tile where the sprite was standing */
int	ft_update(t_program	*game, int map_x, int map_y)
{
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

void	action(t_program *game)
{
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->tile.ptr, game->tile_position.x,
		game->tile_position.y);
	game->nb_items--;
	ft_printf("items left : %d\n", game->nb_items);
	if (game->nb_items == 0)
	{
		//open exit
	}
}
