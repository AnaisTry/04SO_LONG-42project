/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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
