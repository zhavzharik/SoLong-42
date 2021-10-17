/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:18:51 by abridger          #+#    #+#             */
/*   Updated: 2021/10/17 20:35:29 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map_data(t_data **game)
{
	int	line;

	line = 0;
	printf("Map_height: %d\n", (*game)->map_h);
	printf("Map_length: %d\n", (*game)->map_l);
	while (line < (*game)->map_h)
	{
		printf("%d\t line : %s\n", line, (*game)->file_data[line]);
		line++;
	}
}
