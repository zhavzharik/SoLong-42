/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:31:59 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 14:00:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_picture(t_visual **window, t_data **game)
{
	int		img_width;
	int		img_height;

	(*game)->wall = mlx_xpm_file_to_image((*window)->mlx_ptr, PUMP1,
			&img_width, &img_height);
	(*game)->player = mlx_xpm_file_to_image((*window)->mlx_ptr, GHOST2,
			&img_width, &img_height);
	(*game)->cake = mlx_xpm_file_to_image((*window)->mlx_ptr, CAKE,
			&img_width, &img_height);
	(*game)->space = mlx_xpm_file_to_image((*window)->mlx_ptr, ROWAN,
			&img_width, &img_height);
	(*game)->exit = mlx_xpm_file_to_image((*window)->mlx_ptr, HOUSE,
			&img_width, &img_height);
}

char	*create_str_assets(void)
{
	char	*assets;

	assets = (char *)malloc(sizeof(char) * 6);
	assets = "01CPE\0";
	return (assets);
}

t_action	*create_array_function(void)
{
	t_action	*array_func;

	array_func = NULL;
	array_func = (t_action *)malloc(sizeof(5));
	(array_func)[0] = &put_empty;
	(array_func)[1] = &put_wall;
	(array_func)[2] = &put_cake;
	(array_func)[3] = &put_player;
	(array_func)[4] = &put_exit;
	return (array_func);
}
