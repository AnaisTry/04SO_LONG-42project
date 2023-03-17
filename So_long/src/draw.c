/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:27:52 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 12:44:39 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_elements(t_program *game);
static void	draw_sprite(t_program *game);

void	draw_map(t_program	*game)
{
	int	i_row;
	int	i_col;

	ft_printf("draw\n");
	game->tile = ft_new_sprite(game, "sprites/grass_96.xpm");
	game->wall = ft_new_sprite(game, "sprites/trees_96.xpm");
	game->item = ft_new_sprite(game, "sprites/apple_s.xpm");
	game->sprite = ft_new_sprite(game, "sprites/fox_96.xpm");
	game->exit = ft_new_sprite(game, "sprites/door_closed_96.xpm");
	i_row = -1;
	while (game->elements.map[++i_row])
	{
		i_col = -1;
		while (game->elements.map[i_row][++i_col])
		{
			game->elements.type = game->elements.map[i_row][i_col];
			game->elements.pos.x = i_row;
			game->elements.pos.y = i_col;
			draw_elements(game);
			draw_sprite(game);
		}
	}
}

static void	draw_elements(t_program *game)
{
	game->elem_pos.y = game->elements.pos.x * IMG_SCALE;
	game->elem_pos.x = game->elements.pos.y * IMG_SCALE;
	mlx_put_image_to_window(game->mlx, game->window.ptr, game->tile.ptr,
		game->elem_pos.x, game->elem_pos.y);
	if (game->elements.type == WALL)
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->wall.ptr,
			game->elem_pos.x, game->elem_pos.y);
	if (game->elements.type == ITEM)
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->item.ptr,
			game->elem_pos.x, game->elem_pos.y);
	if (game->elements.type == EXIT)
	{
		game->exit_pos.x = game->elem_pos.x;
		game->exit_pos.y = game->elem_pos.y;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->exit.ptr,
			game->exit_pos.x, game->exit_pos.y);
	}
}

static void	draw_sprite(t_program *game)
{
	if (game->elements.type == PLAYER)
	{
		game->sprite_pos.x = game->elem_pos.x;
		game->sprite_pos.y = game->elem_pos.y;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->sprite.ptr,
			game->sprite_pos.x, game->sprite_pos.y);
	}
}
