/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:17:16 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:09:02 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_array_clear(t_data *game)
{
	int	i;

	i = game->map_h;
	if (!game->file_data)
		return ;
	while (i >= 0)
	{
		if (game->file_data[i])
		{
			free(game->file_data[i]);
			game->file_data = NULL;
		}
		i--;
	}
}

void	ft_struct_clear(t_data *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	if (game->file_data)
		ft_array_clear(game);
	if (game)
	{
		free(game);
		game = NULL;
	}
	exit (EXIT_SUCCESS);
}
