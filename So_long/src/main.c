/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:39:34 by angassin          #+#    #+#             */
/*   Updated: 2023/03/03 18:10:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include <unistd.h>

void	game_init(t_program *game);

int	main(int argc, char	**argv)
{
	t_program	game;

	if (argc != 2)
	{
		perror("Wrong number of arguments, correct input: <program> <map>.ber");
		exit(1);
	}
	check_map(argv[1], &game);
	game_init(&game);
	draw_map(&game);

	// game.tile = ft_new_sprite(game.mlx, "sprites/grass64.xpm");
	// game.tile_position.x = 0;
	// game.tile_position.y = 0; 
	// mlx_put_image_to_window(game.mlx, game.window.ptr, game.tile.ptr,
	// 							game.tile_position.x, game.tile_position.y);
	


	
	
	// mlx_pixel_put(mlx_ptr, win_ptr, 20, 250, 0xFFFFFF);
	mlx_key_hook(game.window.ptr, *ft_input, &game);
	//mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx); // event loop
	return (0);
}

/*
	mlx_init() creates a structure with all the variables the mlx will need,															 
	among which the display = connexion identifier to X server.														
	returns a t_xvar or void *0 if failed
*/
void	game_init(t_program *game)
{
	game->mlx = mlx_init();
	game->window = ft_new_window(*game, (game->window.size.x) * IMG_SCALE,
			(game->window.size.y) * IMG_SCALE, "so_long");
}
