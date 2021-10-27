/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:46:52 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:07:44 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	get_component(t_data **game, int x, int y)
{
	char	ch;

	ch = (*game)->file_data[y][x];
	return (ch);
}

int	whether_can_move(t_data **game, int x, int y)
{
	char	ch;

	if (x < 0 || y < 0 || x >= (*game)->map_l || y >= (*game)->map_h)
		return (0);
	ch = (*game)->file_data[y][x];
	if (ch == '1' || (ch == 'E' && (*game)->nb_cake > 0))
		return (0);
	return (1);
}

void	change_map(t_data **game, char ch, int x, int y)
{
	(*game)->file_data[y][x] = ch;
}

void	check_game_score(t_data **game, int x, int y)
{
	if (get_component(game, x, y) == 'C')
	{
		(*game)->nb_cake -= 1;
	}
	(*game)->step += 1;
	if ((*game)->nb_cake == 0)
		(*game)->score += 1;
	if ((*game)->max - (*game)->score == 0 && !(*game)->out)
		(*game)->end = 2;
}

int	whether_won(t_data **game, int x, int y)
{
	char	ch;

	ch = (*game)->file_data[y][x];
	if (ch == 'E' && (*game)->nb_cake == 0)
		return (1);
	return (0);
}
