/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:42:30 by abridger          #+#    #+#             */
/*   Updated: 2021/10/22 20:43:13 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*init_game(t_data *game)
{
	game->map_h = 0;
	game->map_l = 0;
	game->file_data = NULL;
	game->wall = NULL;
	game->wall_rand = NULL;
	game->player_l = NULL;
	game->player_r = NULL;
	game->cake = NULL;
	game->space = NULL;
	game->exit_c = NULL;
	game->exit_o = NULL;
	game->x_pos_player = 0;
	game->y_pos_player = 0;
	game->flag_player = 0;
	game->nb_cake = 0;
	game->game_score = 0;
	game->assets = "01CPE\0";
	game->step = 0;
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

void	init_window(t_data **game)
{
	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr,
			(*game)->map_l * PIC_SIDE, (*game)->map_h * PIC_SIDE, "So Long!");
}
