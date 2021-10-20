/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:42:30 by abridger          #+#    #+#             */
/*   Updated: 2021/10/20 21:40:11 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*init_game(t_data *game)
{
	game->map_h = 0;
	game->map_l = 0;
	game->wall = NULL;
	game->player = NULL;
	game->cake = NULL;
	game->space = NULL;
	game->exit = NULL;
	game->x_pos_player = 0;
	game->y_pos_player = 0;
	game->nb_cake = 0;
	game->game_score = 0;
	game->assets = "01CPE\0"; // create_str_assets();
	return (game);
}

void	init_array(char *file, t_data **game)
{
	int	row;

	get_map_height(file, game);
	get_map_length(file, game);
	(*game)->file_data = (char **)malloc(sizeof(char *) * ((*game)->map_h));
	row = 0;
	while (row < (*game)->map_h)
	{
		(*game)->file_data[row] = (char *)malloc(sizeof(char)
				* ((*game)->map_l + 1));
		row++;
	}
	if (!((*game)->file_data))
		exit (0);
}

t_visual	*init_window(t_visual *window, t_data *game)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, game->map_l * PIC_SIDE,
			game->map_h * PIC_SIDE, "So Long!");
	return (window);
}
