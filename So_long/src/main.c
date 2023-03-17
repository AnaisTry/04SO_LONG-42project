/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:39:34 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 13:10:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	game_init(t_program *game);

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
	mlx_key_hook(game.window.ptr, *ft_input, &game);
	mlx_loop(game.mlx);
	return (0);
}

/*	
	mlx_init() creates a structure with all the variables the mlx will need,
	among which the display = connexion identifier to X server.														
	returns a t_xvar or void *0 if failed
*/
static void	game_init(t_program *game)
{
	game->mlx = mlx_init();
	game->window = ft_new_window(*game, (game->window.size.x) * IMG_SCALE,
			(game->window.size.y) * IMG_SCALE, "so_long");
	game->wall.ptr = NULL;
	game->tile.ptr = NULL;
	game->item.ptr = NULL;
	game->sprite.ptr = NULL;
	game->exit.ptr = NULL;
	game->nb_mov = 0;
	game->exit_open = false;
}
