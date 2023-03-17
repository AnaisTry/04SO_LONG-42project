/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:54:12 by angassin          #+#    #+#             */
/*   Updated: 2023/03/06 23:38:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	Returns a struct containing the datas of the new image
	
	mlx_get_data_addr() :
	mlx function that returns a pointer to the first pixel of the given image :
	* 	the line size is the amount of pixels in one line of the image
	* 	the endian contains info on how the colors are stored, not used on mac
*/
t_image	ft_new_image(t_program *game, int width, int height)
{
	t_image	img;

	img.ptr = mlx_new_image(game->mlx, width, height);
	if (!img.ptr)
		error_exit("file error\n", game);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size,
			&img.endian);
	return (img);
}

/* Returns an image with the sprite found in <path> */
t_image	ft_new_sprite(t_program *game, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx, path, &img.size.x, &img.size.y);
	if (!img.ptr)
		error_exit("file error\n", game);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size,
			&img.endian);
	return (img);
}
