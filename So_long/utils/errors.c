/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:30:15 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 17:38:13 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(char *err_message, t_program *game)
{
	ft_printf("Error\n");
	perror(err_message);
	if (game->elements.map != NULL)
		free_array(game->elements.map, game->window.size.y);
	exit (1);
}
