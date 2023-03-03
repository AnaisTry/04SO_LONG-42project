/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:54:12 by angassin          #+#    #+#             */
/*   Updated: 2023/03/01 12:00:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

/* 
	Returns a struct containing the datas of the new image
	
	mlx_get_data_addr() :
	mlx function that returns a pointer to the first pixel of the given image :
	* 	the line size is the amount of pixels in one line of the image
	* 	the endian contains info on how the colors are stored, not used on mac
*/
t_image	ft_new_image(void	*mlx, int width, int height)
{
	t_image	img;

	img.ptr = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size,
			&img.endian);
	return (img);
}

/* Returns an image with the sprite found in <path> */
t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size,
			&img.endian);
	return (img);
}
