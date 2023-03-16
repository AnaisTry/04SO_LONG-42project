/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:10 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 17:38:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_program *game)
{
	ft_printf("closed\n");
	if (game->mlx != NULL)
	{
		ft_printf("destroy window\n");
		mlx_destroy_window(game->mlx, game->window.ptr);
	}
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
	ft_printf("open window\n");
	mlx_hook(game.window.ptr, DESTROY_NOTIFY, MASK, ft_close, &game);
	return (game.window);
}
