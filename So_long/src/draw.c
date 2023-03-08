/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:27:52 by angassin          #+#    #+#             */
/*   Updated: 2023/03/08 14:59:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_background(t_program *game, int i_row, int i_col);
void	draw_elements(t_program *game, int i_row, int i_col);

void	draw_map(t_program	*game)
{
	int		i_row;
	int		i_col;

	game->tile = ft_new_sprite(game->mlx, "sprites/grass_96.xpm");
	game->wall = ft_new_sprite(game->mlx, "sprites/trees_96.xpm");
	game->item = ft_new_sprite(game->mlx, "sprites/strawberry_96.xpm");
	game->sprite = ft_new_sprite(game->mlx, "sprites/fox_96.xpm");
	game->exit = ft_new_sprite(game->mlx, "sprites/blue_96.xpm");
	i_row = -1;
	while (game->map_infos.map[++i_row])
	{
		i_col = -1;
		while (game->map_infos.map[i_row][++i_col])
		{
			draw_background(game, i_row, i_col);
			draw_elements(game, i_row, i_col);
		}
	}
	ft_printf("nb_items : %d\n", game->nb_items);
}

/* put grass as background or sky for the exit */
void	draw_background(t_program *game, int i_row, int i_col)
{
	char	type;

	type = game->map_infos.map[i_row][i_col];
	if (type == EXIT)
	{
		game->exit_pos.x = i_col * IMG_SCALE;
		game->exit_pos.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->exit.ptr,
			game->exit_pos.x, game->exit_pos.y);
		game->exit = ft_new_sprite(game->mlx, "sprites/door_closed_96.xpm");
	}
	else
	{
		game->tile_pos.y = i_row * IMG_SCALE;
		game->tile_pos.x = i_col * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->tile.ptr,
			game->tile_pos.x, game->tile_pos.y);
	}
}

void	draw_elements(t_program *game, int i_row, int i_col)
{
	char	type;

	type = game->map_infos.map[i_row][i_col];
	if (type == WALL)
	{
		game->wall_pos.y = i_row * IMG_SCALE;
		game->wall_pos.x = i_col * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->wall.ptr,
			game->wall_pos.x, game->wall_pos.y);
	}
	if (type == PLAYER)
	{
		game->sprite_pos.x = i_col * IMG_SCALE;
		game->sprite_pos.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->sprite.ptr,
			game->sprite_pos.x, game->sprite_pos.y);
	}
	if (type == ITEM)
	{
		game->nb_items++;
		game->item_pos.x = i_col * IMG_SCALE;
		game->item_pos.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->item.ptr,
			game->item_pos.x, game->item_pos.y);
	}
	if (type == EXIT)
	{
		game->exit_pos.x = i_col * IMG_SCALE;
		game->exit_pos.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->exit.ptr,
			game->exit_pos.x, game->exit_pos.y);
	}
}
