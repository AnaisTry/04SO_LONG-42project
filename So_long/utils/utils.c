/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:49:44 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 17:10:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(char *err_message, t_program *game)
{
	ft_printf("Error\n");
	perror(err_message);
	if (game->elements.map != NULL)
		free_array(game->elements.map);
	destroy_images(game);
	exit (1);
}

int	map_height(char	**map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

int	count_elements(t_program *game, char type)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = -1;
	while (game->elements.map[++i])
	{
		j = -1;
		while (game->elements.map[i][++j])
			if (game->elements.map[i][j] == type)
				nb++;
	}
	return (nb);
}

void	*free_array(char **arr)
{
	int	row;

	row = 0;
	while (arr[row] != NULL)
	{
		free(arr[row]);
		row++;
	}
	free(arr);
	return (NULL);
}

void	destroy_images(t_program *game)
{
	if (game->wall.ptr != NULL)
		mlx_destroy_image(game->mlx, game->wall.ptr);
	if (game->tile.ptr != NULL)
		mlx_destroy_image(game->mlx, game->tile.ptr);
	if (game->item.ptr != NULL)
		mlx_destroy_image(game->mlx, game->item.ptr);
	if (game->sprite.ptr != NULL)
		mlx_destroy_image(game->mlx, game->sprite.ptr);
	if (game->exit.ptr != NULL)
		mlx_destroy_image(game->mlx, game->exit.ptr);
}
