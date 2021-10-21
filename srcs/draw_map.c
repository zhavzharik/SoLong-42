/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:10:07 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 17:01:50 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_index(char *assets, char ch)
{
	int	indx;

	indx = 0;
	while (indx < (int)ft_strlen(assets))
	{
		if (assets[indx] == ch)
		{
			return (indx);
		}
		indx++;
	}
	return (indx);
}

void	draw_map(t_data **game)
{
	int			line;
	int			columns;
	int			indx;

	line = 0;
	while (line < (*game)->map_h * PIC_SIDE)
	{
		columns = 0;
		while (columns < (*game)->map_l * PIC_SIDE)
		{
			indx = get_index((*game)->assets,
					(*game)->file_data[line / PIC_SIDE][columns / PIC_SIDE]);
			execute_func(game, indx, columns, line);
			columns += PIC_SIDE;
		}
		line += PIC_SIDE;
	}
}
