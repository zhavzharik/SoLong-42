/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:14:27 by abridger          #+#    #+#             */
/*   Updated: 2021/10/26 23:10:25 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data			*game;

	if (argc == 2)
	{
		game = (t_data *)malloc(sizeof(t_data));
		if (!game)
			return (-1);
		check_data(argv[1]);
		init_game(game);
		init_game_bonus(game);
		ft_reading_file(argv[1], &game);
		game_proceed(&game);
	}
	return (0);
}
