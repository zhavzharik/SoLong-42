/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:42:30 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:10:24 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_data	*init_game(t_data *game)
{
	game->map_h = 0;
	game->map_l = 0;
	game->file_data = NULL;
	game->wall = NULL;
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
	game->score = 0;
	game->max = 0;
	game->assets = "01CPE\0";
	game->step = 0;
	game->prev_step = 0; // for mandatory
	game->out = 0;
	game->end = 0;
	game->counter = 0;
	return (game);
}

t_data	*init_game_bonus(t_data *game)
{
	game->m_1 = NULL;
	game->m_2 = NULL;
	game->m_3 = NULL;
	game->pump_1 = NULL;
	game->pump_2 = NULL;
	game->pump_4 = NULL;
	game->enemy_1 = NULL;
	game->enemy_2 = NULL;
	game->enemy_3 = NULL;
	game->enem_c = 0;
	return (game);
}

void	init_array(char *file, t_data **game)
{
	get_map_height(file, game);
	get_map_length(file, game);
	(*game)->file_data = malloc(sizeof(char *) * ((*game)->map_h));
	if (!((*game)->file_data))
		exit (EXIT_FAILURE);
}

void	init_window(t_data **game)
{
	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr,
			(*game)->map_l * PIC_SIDE, (*game)->map_h * PIC_SIDE, "So Long!");
}
