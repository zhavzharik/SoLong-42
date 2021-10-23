/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:17:16 by abridger          #+#    #+#             */
/*   Updated: 2021/10/23 17:36:46 by abridger         ###   ########.fr       */
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
		temp = array[i++];
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
		game->file_data = NULL;
		game->map_h = 0;
		game->map_l = 0;
		game->wall = NULL;
		game->m_1 = NULL;
		game->m_2 = NULL;
		game->m_3 = NULL;
		game->m_4 = NULL;
		game->m_5 = NULL;
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
		game->step = 0;
		game->out = 0;
	}
}

void	ft_clear_window(t_data *game)
{
	if (game)
	{
		game->mlx_ptr = NULL;
		game->win_ptr = NULL;
	}
}

void	ft_all_clear(t_data *game)
{
	if (game)
	{
		ft_struct_clear(game);
		// ft_clear_window(game);
		free(game);
		game = NULL;
	}
}
