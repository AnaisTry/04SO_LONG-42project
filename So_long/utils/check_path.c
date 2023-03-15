/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:35:53 by angassin          #+#    #+#             */
/*   Updated: 2023/03/14 18:59:24 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**array_dup(t_map *original);

void	check_path(t_program	*game)
{
	int		x;
	int		y;
	char	**copy;

	x = 0;
	y = 0;
	copy = array_dup(game->elements.map);
	while (copy[y] && copy[y][x] != PLAYER)
	{
		x = 0;
		y++;
		while (copy[y][x] && copy[y][x] != PLAYER)
			x++;
	}
	game->elements.pos.y = y;
	game-> elements.pos.x = x;
	bfsearch_elements(copy, game->elements);
}

/* duplicates the map to be able to check the path*/
char	**array_dup(t_map *original)
{
	int		height;
	int		i;
	char	**copy;

	height = original->pos.y;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Mem allocation, could not duplicate the map\n");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original->map[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/* 
	recursive breadth first search to check all the elements reachable
	on the map
*/
void	bfsearch_elements(char	**map, t_map elements)
{


}