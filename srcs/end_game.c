/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:41:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/25 23:42:58 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_data **game)
{
	(void)game;
	// if (game)
	// {
	// 	printf("ft_close\n");
	// 	ft_struct_clear(game);
	// }
	exit (0);
	return (0);
}

int	put_game_end(t_data **game)
{
	int	i;
	int	j;

	i = (*game)->map_l / 2 * PIC_SIDE;
	j = (*game)->map_h / 2 * PIC_SIDE;
	if ((*game)->out > 0 && !(*game)->end)
	{
		mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
		mlx_string_put((*game)->mlx_ptr, (*game)->win_ptr, i, j, ORANGE, WON);
	}
	else if ((*game)->end == 1)
	{
		draw_map(game);
		mlx_string_put((*game)->mlx_ptr, (*game)->win_ptr, i, j, ORANGE, LOST);
	}
	else if ((*game)->end == 2)
	{
		mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
		mlx_string_put((*game)->mlx_ptr, (*game)->win_ptr, i, j, ORANGE, LOST);
	}
	return (0);
}

void	set_max(t_data **game)
{
	int	i;
	int	j;

	i = (*game)->map_l - 2;
	j = (*game)->map_h - 2;
	// (*game)->max = j * (i / 2 + i % 2) + i / 2;
	(*game)->max = i + j + 4;
}
