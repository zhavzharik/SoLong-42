/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:31:59 by abridger          #+#    #+#             */
/*   Updated: 2021/10/18 17:22:09 by abridger         ###   ########.fr       */
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

char	**create_array_assets(void)
{
	char	**assets;

	assets = (char **)malloc(sizeof(char *) * 5);
	(assets)[s] = ft_strdup("0\0");
	(assets)[w] = ft_strdup("1\0");
	(assets)[c] = ft_strdup("C\0");
	(assets)[p] = ft_strdup("p\0");
	(assets)[e] = ft_strdup("E\0");
	return (assets);
}

t_action	*create_array_function(void)
{
	t_action	*array_func;

	array_func = NULL;
	array_func = (t_action *)malloc(sizeof(5));
	(array_func)[s] = &put_empty;
	(array_func)[w] = &put_wall;
	(array_func)[c] = &put_cake;
	(array_func)[p] = &put_player;
	(array_func)[e] = &put_exit;
	return (array_func);
}
