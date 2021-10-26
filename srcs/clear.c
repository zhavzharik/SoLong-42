/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:17:16 by abridger          #+#    #+#             */
/*   Updated: 2021/10/26 23:56:02 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_array_clear(char ***array, int row)
{
	int		i;
	char	*temp;
	int		line; // delete

	i = 0;
	printf("Row:%d\n", row);
	while (i < row && (*array)[i])
	{
		printf("I before free: %d\n", i);
		printf("(*array)[i]: %s\n", (*array)[i]);
		temp = (*array)[i];
		free(temp);
		temp = NULL;
		(*array)[i] = NULL;
		if ((*array)[i])
			printf("(array)[i] after free temp: %s\n", (*array)[i]);
		if ((*array)[i] !=  NULL)
			printf("(array)[i] after free temp...: %s\n", (*array)[i + 1]);
		if (temp)
			printf("temp after free temp: %s\n", temp);
		i++;
	}
	if ((*array))
	{
		line = 0;
		while (line < row)
		{
			printf("*Array\n");
			printf("Array : %s\n", **array);
			// printf("%d\t line : %s\n", line, *array[line]);
			line++;
		}
		printf("*Array clear\n");
		free((*array));
		(*array) = NULL;
	}
}

// void	ft_array_clear(char ***array, int row)
// {
// 	int		i;
// 	char	*temp;
// 	char	**table;

// 	i = row - 1;
// 	if (!array)
// 		return ;
// 	table = *array;
// 	printf("Row:%d\n", row);
// 	while (i >= 0)
// 	{
// 		printf("I before free: %d\n", i);
// 		printf("(table)[%d]: %s\n", i, (*table)[i]);
// 		temp = *table[i];
// 		if (temp)
// 		{
// 			printf("temp: %s\n", temp);
// 			free(temp);
// 			temp = NULL;
// 		}
// 		printf("(array)[i] after free temp: %s\n", (*array)[i]);
// 		i--;
// 	}
// 	if ((*array))
// 	{
// 		printf("(array): %s\n", (**array));
// 		free((*array));
// 		array = NULL;
// 	}
// }

void	ft_struct_clear(t_data **game)
{
	int		i;
	char	**copy;
	int		line;

	copy = (*game)->file_data;
	if (game)
	{
		i = (*game)->map_h;
		// ft_array_clear((*game)->file_data, i);
		ft_array_clear(&((*game)->file_data), i);
		// print_map_data(game); //
		if (!(*game)->file_data)
			printf("no char\n");
		if ((*game))
		{
			free((*game));
			game = NULL;
		}
		if (!game)
			printf("struct_cleared\n");
	}
	line = 0;
	if (copy)
	{
		printf("Copy");
		free(copy);
		copy = NULL;
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
