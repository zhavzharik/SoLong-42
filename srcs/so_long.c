/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:14:27 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 14:27:52 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data		*game;
	t_visual	*window;

	(void)argc;
	game = (t_data *)malloc(sizeof(t_data));
	if (!game)
		return (-1);
	window = (t_visual *)malloc(sizeof(t_visual));
	if (!window)
		return (-1);
	init_game(game);
	ft_reading_file(argv[1], &game);
	init_window(window, game);
	// if (!ft_reading_file(argv[1], &game))
	// {
	// 	free(game);
	// 	return (0);
	// }
	draw_map(&window, &game);
	// draw_test2(&window, &game); // delete
	// print_map_data(&game); // delete
	ft_struct_clear(&game);
	ft_clear_window(&window);
	return (0);
}
