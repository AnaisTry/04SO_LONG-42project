/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:44:15 by angassin          #+#    #+#             */
/*   Updated: 2023/03/15 15:45:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_file(char *file);
void	check_elements(t_program *game);
void	check_grid(t_program *game);
char	*save_lines(char *lines, char *current_line, int fd);

/* 
	check the extension of the map_file
	import the content of the map_file and retrieve datas
*/
void	check_map(char	*map_file, t_program *game)
{
	(void)game;
	if (ft_strrncmp(map_file, MAP_EXT, 4))
		error_exit("Wrong file extension");
	game->elements.map = read_file(map_file);
	game->window.size.x = ft_strlen(game->elements.map[0]);
	ft_printf("window width : %d\n", game->window.size.x);
	game->window.size.y = map_height(game->elements.map);
	ft_printf("window height : %d\n", game->window.size.y);
	check_elements(game);
	check_grid(game);
	check_path(game);
}

char	**read_file(char *file)
{
	char	**map;
	char	*lines;
	char	*current_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit("");
	lines = get_next_line(fd);
	if (!lines || lines[0] == '\n')
		error_exit("Invalid map");
	current_line = get_next_line(fd);
	lines = save_lines(lines, current_line, fd);
	ft_printf("Map : \n%s\n", lines);
	map = ft_split(lines, '\n');
	if (lines)
		free(lines);
	close(fd);
	return (map);
}

char	*save_lines(char	*lines, char *current_line, int fd)
{
	char	*tmp;

	while (current_line)
	{
		if (current_line[0] == '\n')
			error_exit("Invalid map");
		tmp = lines;
		lines = ft_strjoin(lines, current_line);
		free(tmp);
		free(current_line);
		current_line = get_next_line(fd);
	}
	return (lines);
}

void	check_elements(t_program *game)
{
	game->nb_items = count_elements(game, ITEM);
	ft_printf("nb_elements : %d\n", game->nb_items);
	if (game->nb_items < 1)
		error_exit("At least one item is required on the map");
	else if (count_elements(game, PLAYER) != 1)
		error_exit("There must be only one player on the map");
	else if (count_elements(game, EXIT) != 1)
		error_exit("There must be only one exit on the map");
}

/* 
	checks that the map is rectangular and surrounded by walls
	checks that there are only valid characters on the map 
*/
// ft_printf("wall value is : %d\n", WALL);
//ft_printf("map[%d][0] is '%c'\n", i_row, (char)game->map[i_row][0]);
//ft_printf("map[%d][%d] is '%c'\n", i_row, game->window.size.x - 1,
//	(char)game->map[i_row][game->window.size.x - 1]);
//ft_printf("map[%d][window.size.x - 1] is %d\n", i_row,
//game->window.size.x - 1);
//ft_printf("map[window.size.y - 1][%d] is %d\n", i_col, 
//game->window.size.y - 1);
void	check_grid(t_program *game)
{
	int	i_row;
	int	i_col;

	i_row = -1;
	while (game->elements.map[++i_row])
	{
		if (game->elements.map[i_row][0] != WALL
			|| game->elements.map[i_row][game->window.size.x - 1] != WALL)
			error_exit("Invalid map : not a rectangle or missing "
				"wall at the end of a row");
		i_col = -1;
		while (game->elements.map[i_row][++i_col])
		{
			if (game->elements.map[0][i_col] != WALL ||
				game->elements.map[game->window.size.y - 1][i_col] != WALL)
				error_exit("Invalid map : not a rectangle or missing "
					"wall at the end of a column");
			if (!ft_strchr(VALID_CHARS, game->elements.map[i_row][i_col]))
				error_exit("Invalid map : unknown element");
		}
	}
}
