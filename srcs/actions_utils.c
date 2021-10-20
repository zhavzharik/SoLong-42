/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:46:52 by abridger          #+#    #+#             */
/*   Updated: 2021/10/20 19:36:37 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	get_component(t_data **game, int x, int y)
{
	char	ch;

	ch = (*game)->file_data[x][y];
	return (ch);
}

int	whether_can_move(t_data **game, int x, int y)
{
	char	ch;

	if (x < 0 || y < 0 || x >= (*game)->map_l || y >= (*game)->map_h)
		return (0);
	ch = (*game)->file_data[x][y];
	if (ch == '1' || (ch == 'E' && (*game)->nb_cake > 0))
		return (0);
	return (1);
}

void	change_map(t_data **game, char ch, int x, int y)
{
	(*game)->file_data[x][y] = ch;
}

void	check_game_score(t_data **game, int x, int y)
{
	if (get_component(game, x, y) == 'C')
	{
		(*game)->nb_cake -= 1;
		(*game)->game_score += 1;
	}
}
