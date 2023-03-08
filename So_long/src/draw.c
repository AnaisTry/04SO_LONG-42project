/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:27:52 by angassin          #+#    #+#             */
/*   Updated: 2023/03/08 13:51:19 by angassin         ###   ########.fr       */
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
	game->exit = ft_new_sprite(game->mlx, "sprites/door_closed_96.xpm");
	i_row = -1;
	while (game->map[++i_row])
	{
		i_col = -1;
		while (game->map[i_row][++i_col])
		{
			draw_background(game, i_row, i_col);
			draw_elements(game, i_row, i_col);
		}
	}
	ft_printf("nb_items : %d\n", game->nb_items);
}

void	draw_background(t_program *game, int i_row, int i_col)
{
	game->tile_position.y = i_row * IMG_SCALE;
	game->tile_position.x = i_col * IMG_SCALE;
	mlx_put_image_to_window(game->mlx, game->window.ptr, game->tile.ptr,
		game->tile_position.x, game->tile_position.y);
}

void	draw_elements(t_program *game, int i_row, int i_col)
{
	char	type;

	type = game->map[i_row][i_col];
	if (type == WALL)
	{
		game->wall_position.y = i_row * IMG_SCALE;
		game->wall_position.x = i_col * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->wall.ptr,
			game->wall_position.x, game->wall_position.y);
	}
	if (type == PLAYER)
	{
		game->sprite_position.x = i_col * IMG_SCALE;
		game->sprite_position.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->sprite.ptr,
			game->sprite_position.x, game->sprite_position.y);
	}
	if (type == ITEM)
	{
		//ft_printf("entered item : %c ", type);
		//ft_printf("coordinates item [%d][%d]\n", i_row, i_col);
		game->nb_items++;
		game->item_position.x = i_col * IMG_SCALE;
		game->item_position.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->item.ptr,
			game->item_position.x, game->item_position.y);
	}
	if (type == EXIT)
	{
		// game->out.x = i_col;
		// game->out.y = i_row;
		game->exit_position.x = i_col * IMG_SCALE;
		game->exit_position.y = i_row * IMG_SCALE;
		mlx_put_image_to_window(game->mlx, game->window.ptr, game->exit.ptr,
			game->exit_position.x, game->exit_position.y);
	}
}
