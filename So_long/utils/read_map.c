/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:44:15 by angassin          #+#    #+#             */
/*   Updated: 2023/03/09 22:34:46 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_file(char *file);
void	check_walls(t_program *game);

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
	check_walls(game);
}

//ft_printf("all the lines: \n%s\n", lines);
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
	while (current_line)
	{
		if (current_line[0] == '\n')
			error_exit("Invalid map");
		lines = ft_strjoin(lines, current_line);
		free(current_line);
		current_line = get_next_line(fd);
	}
	map = ft_split(lines, '\n');
	if (lines)
		free(lines);
	close(fd);
	return (map);
}

/* checks that the map is rectangular and surrounded by walls */
// ft_printf("wall value is : %d\n", WALL);
//ft_printf("map[%d][0] is '%c'\n", i_row, (char)game->map[i_row][0]);
//ft_printf("map[%d][%d] is '%c'\n", i_row, game->window.size.x - 1,
//	(char)game->map[i_row][game->window.size.x - 1]);
//ft_printf("map[%d][window.size.x - 1] is %d\n", i_row,
//game->window.size.x - 1);
//ft_printf("map[window.size.y - 1][%d] is %d\n", i_col, 
//game->window.size.y - 1);
void	check_walls(t_program *game)
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
		}
	}
}
