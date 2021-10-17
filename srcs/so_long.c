/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:14:27 by abridger          #+#    #+#             */
/*   Updated: 2021/10/17 20:39:33 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*game;

	(void)argc;
	game = (t_data *)malloc(sizeof(t_data));
	if (!game)
		return (-1);
	init_game(game);
	ft_reading_file(argv[1], &game);
	// if (!ft_reading_file(argv[1], &game))
	// {
	// 	free(game);
	// 	return (0);
	// }
	print_map_data(&game); // delete
	return (0);
}

// 	int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*img;
// 	int		img_width;
// 	int		img_height;

// 	img_width = 80;
// 	img_height = 80;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "So Long!");
// 	img = mlx_xpm_file_to_image(mlx_ptr, WALL, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
// 	mlx_loop(mlx_ptr);
// }
