/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.nb_elemen                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:33:15 by angassin          #+#    #+#             */
/*   Updated: 2023/03/09 22:33:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_height(char	**map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	ft_printf("map height : %d\n", i);
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
	ft_printf("nb_elements : %d\n", nb);
	return (nb);
}
