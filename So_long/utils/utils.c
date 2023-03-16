/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:49:44 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 12:54:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	*free_array(char **arr, int row)
{
	while (row--)
		free(arr[row]);
	free(arr);
	return (NULL);
}
