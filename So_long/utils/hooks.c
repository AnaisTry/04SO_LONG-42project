/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:50:07 by angassin          #+#    #+#             */
/*   Updated: 2023/03/03 18:26:50 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	Movement of the sprite according to user input :
	1. erases previous image
	2. determines the new position of the sprite according to the key pressed
	3. displays the new image
*/
int	ft_input(int key, void *param)
{
	t_program	*game;

	game = (t_program *)param;
	//mlx_clear_window(game->mlx, game->window.ptr);
	if (key == esc)
		ft_close(game);
	if (key == w || key == up)
	{
		ft_update(game);
		game->sprite_position.y -= game->sprite.size.y;
	}
	if (key == a || key == left)
	{	
		ft_update(game);
		game->sprite_position.x -= game->sprite.size.x;
	}
	if (key == s || key == down)
	{
		ft_update(game);
		game->sprite_position.y += game->sprite.size.y;
	}
	if (key == d || key == right)
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
