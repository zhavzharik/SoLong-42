/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:17:16 by abridger          #+#    #+#             */
/*   Updated: 2021/10/25 20:43:56 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_array_clear(char ***array, int row)
{
	int		i;

	i = 0;
	while (i <= row)
	{
		free((*array)[i]);
		i++;
	}
	free((*array));
	(*array) = NULL;
}

// void	ft_array_clear(char **array, int row)
// {
// 	int		i;
// 	char	*temp;

// 	i = 0;
// 	if (!array)
// 		return ;
// 	while (i < row)
// 	{
// 		temp = array[i];
// 		free(temp);
// 		temp = NULL;
// 		i++;
// 	}
// 	free(array);
// 	*array = NULL;
// }

void	ft_struct_clear(t_data **game)
{
	int	i;

	i = (*game)->map_h;
	if (game)
	{
		ft_array_clear(&((*game)->file_data), i);
		free(*game);
		game = NULL;
		printf("struct_clear\n");
	}
}

// void	ft_bonus_clear(t_data *game)
// {
// 	game->m_1 = NULL;
// 	game->m_2 = NULL;
// 	game->m_3 = NULL;
// 	game->pump_1 = NULL;
// 	game->pump_2 = NULL;
// 	game->pump_4 = NULL;
// 	game->enemy_1 = NULL;
// 	game->enemy_2 = NULL;
// 	game->enemy_3 = NULL;
// 	game->enem_c = 0;
// }

// void	ft_clear_window(t_data *game)
// {
// 	if (game)
// 	{
// 		game->mlx_ptr = NULL;
// 		game->win_ptr = NULL;
// 	}
// }

// void	ft_all_clear(t_data *game)
// {
// 	if (game)
// 	{
// 		ft_struct_clear(game);
// 		ft_bonus_clear(game);
// 		ft_clear_window(game);
// 		free(game);
// 		game = NULL;
// 	}
// }
