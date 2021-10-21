/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:17:16 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 17:05:40 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_array_clear(char **array, int row)
{
	int		i;
	char	*temp;

	i = 0;
	if (!array)
		return ;
	while (i < row)
	{
		temp = array[row++];
		free(temp);
		temp = NULL;
	}
	free(array);
	*array = NULL;
}

void	ft_struct_clear(t_data *game)
{
	if (game)
	{
		if (game->file_data)
			ft_array_clear(game->file_data, game->map_h);
		game->map_h = 0;
		game->map_l = 0;
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
		game->game_score = 0;
		game->assets = NULL;
	}
	free(game);
	game = NULL;
}

void	ft_clear_window(t_data **game)
{
	if (*game)
	{
		(*game)->mlx_ptr = NULL;
		(*game)->win_ptr = NULL;
	}
	if (game)
		free(game);
}
