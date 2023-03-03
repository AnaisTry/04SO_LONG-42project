/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:10 by angassin          #+#    #+#             */
/*   Updated: 2023/03/03 15:50:07 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_program *game)
{
	(void)game;
	ft_printf("here close\n");
	//mlx_destroy_window(game->mlx, game->window.ptr);
	exit(0);
}

/*
	Create the window and allow to close it with the destroynotify X11 event.
	Returns NULL if failed
	On MacOS - Cocoa (AppKit) and OpenGL - version, minilibx has partial support
	of X11 events and doesn’t support X11 mask 
	(x_mask argument of mlx_hook is useless, keep it at 0)
*/
t_window	ft_new_window(t_program game, int width, int height, char *name)
{
	game.window.ptr = mlx_new_window(game.mlx, width, height, name);
	game.window.size.x = width;
	game.window.size.y = height;
	ft_printf("here window\n");
	mlx_hook(game.window.ptr, DESTROY_NOTIFY, MASK, ft_close, &game);
	return (game.window);
}
