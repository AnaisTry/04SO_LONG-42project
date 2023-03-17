/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:35:53 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 16:54:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**array_dup(t_program *game);
static void	bfsearch_elements(char	**map, t_program *game, int x, int y);

void	check_path(t_program	*game)
{
	int		x;
	int		y;
	char	**copy;

	x = 0;
	y = 0;
	copy = array_dup(game);
	while (copy[y] && copy[y][x] != PLAYER)
	{
		x = 0;
		y++;
		while (copy[y][x] && copy[y][x] != PLAYER)
			x++;
	}
	game->elements.check_exit = 0;
	game->elements.check_items = 0;
	bfsearch_elements(copy, game, x, y);
	if (game->elements.check_exit == false
		|| game->elements.check_items != game->nb_items)
	{
		free_array(copy);
		error_exit("Invalid map : no valid path", game);
	}
	free_array(copy);
}

static char	**array_dup(t_program *game)
{
	int		height;
	int		i;
	char	**copy;

	height = game->window.size.y;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Mem allocation, could not duplicate the map\n", game);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(game->elements.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

/* 
	recursive breadth first search to check all the elements reachable
	on the map
*/
static void	bfsearch_elements(char	**map, t_program *game, int x, int y)
{
	if (map[y][x] == ITEM)
		game->elements.check_items++;
	else if (map[y][x] == EXIT)
		game->elements.check_exit = true;
	if (x >= game->window.size.x || y >= game->window.size.y || x < 0 || y < 0
		|| map[y][x] == WALL || map[y][x] == CHECKED || map[y][x] == EXIT)
		return ;
	map[y][x] = CHECKED;
	bfsearch_elements(map, game, x + 1, y);
	bfsearch_elements(map, game, x - 1, y);
	bfsearch_elements(map, game, x, y + 1);
	bfsearch_elements(map, game, x, y - 1);
}
