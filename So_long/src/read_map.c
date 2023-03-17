/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:44:15 by angassin          #+#    #+#             */
/*   Updated: 2023/03/16 17:35:46 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**read_file(char *file, t_program *game);
static void	check_elements(t_program *game);
static void	check_grid(t_program *game);
static char	*save_lines(char *lines, int fd, t_program *game);

/* 
	check the extension of the map_file
	import the content of the map_file and retrieve datas
	check the validity of the map
*/
void	check_map(char	*map_file, t_program *game)
{
	if (ft_strrncmp(map_file, MAP_EXT, 4))
		error_exit("Wrong file extension", game);
	game->elements.map = read_file(map_file, game);
	game->window.size.x = ft_strlen(game->elements.map[0]);
	ft_printf("window width : %d\n", game->window.size.x);
	game->window.size.y = map_height(game->elements.map);
	ft_printf("window height : %d\n", game->window.size.y);
	check_elements(game);
	check_grid(game);
	check_path(game);
}

static char	**read_file(char *file, t_program *game)
{
	char	**map;
	char	*lines;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit("", game);
	lines = get_next_line(fd);
	if (!lines || lines[0] == '\n')
	{
		close(fd);
		error_exit("Invalid map", game);
	}
	lines = save_lines(lines, fd, game);
	ft_printf("Map : \n%s\n", lines);
	map = ft_split(lines, '\n');
	if (lines)
		free(lines);
	close(fd);
	return (map);
}

static char	*save_lines(char *lines, int fd, t_program *game)
{
	char	*tmp;
	char	*current_line;

	current_line = get_next_line(fd);
	while (current_line)
	{
		if (current_line[0] == '\n')
			error_exit("Invalid map", game);
		tmp = lines;
		lines = ft_strjoin(lines, current_line);
		free(tmp);
		free(current_line);
		current_line = get_next_line(fd);
	}
	return (lines);
}

static void	check_elements(t_program *game)
{
	game->nb_items = count_elements(game, ITEM);
	ft_printf("nb_items : %d\n", game->nb_items);
	if (game->nb_items < 1)
		error_exit("At least one item is required on the map", game);
	else if (count_elements(game, PLAYER) != 1)
		error_exit("There must be only one player on the map", game);
	else if (count_elements(game, EXIT) != 1)
		error_exit("There must be only one exit on the map", game);
}

/* 
	checks that the map is rectangular and surrounded by walls
	checks that there are only valid characters on the map 
*/
static void	check_grid(t_program *game)
{
	int	i_row;
	int	i_col;

	i_row = -1;
	while (game->elements.map[++i_row])
	{
		if (game->elements.map[i_row][0] != WALL
			|| game->elements.map[i_row][game->window.size.x - 1] != WALL)
			error_exit("Invalid map : not a rectangle or missing "
				"wall at the end of a row", game);
		i_col = -1;
		while (game->elements.map[i_row][++i_col])
		{
			if (game->elements.map[0][i_col] != WALL ||
				game->elements.map[game->window.size.y - 1][i_col] != WALL)
				error_exit("Invalid map : not a rectangle or missing "
					"wall at the end of a column", game);
			if (!ft_strchr(VALID_CHARS, game->elements.map[i_row][i_col]))
				error_exit("Invalid map : unknown element", game);
		}
	}
}
