/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:55:51 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 17:14:04 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_is_map_char(int ch)
{
	if (ch == 48 || ch == 49 || ch == 67 || ch == 69 || ch == 80)
		return (1);
	else
		return (0);
}

static void	check_line(char *line)
{
	size_t	len;
	size_t	indx;

	indx = 0;
	len = ft_strlen(line);
	while (indx < len)
	{
		if (ft_is_map_char(line[indx]) == 0)
			put_error_message(3);
		indx++;
	}
}

static int	check_exit(char *line)
{
	size_t	len;
	size_t	indx;

	indx = 0;
	len = ft_strlen(line);
	while (indx < len)
	{
		if (line[indx] == 69)
			return (1);
		indx++;
	}
	return (0);
}

void	check_map_character(char *file)
{
	int		rd;
	int		fd;
	char	*line;
	int		check;

	check = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	rd = 1;
	while (get_next_line(fd, &line))
	{
		check_line(line);
		if (check_exit(line))
			check += 1;
		if (line)
			free(line);
	}
	if (line)
		free(line);
	close (fd);
	if (check == 0)
		put_error_message(2);
}

void	check_wall(t_data *game)
{
	int			line;
	int			columns;
	int			check;

	line = 0;
	check = 0;
	while (line < game->map_h)
	{
		columns = 0;
		while (columns < game->map_l)
		{
			if ((game->file_data[line][columns] != '1' && line == 0) ||
				(game->file_data[line][columns] != '1' && columns == 0) ||
				(game->file_data[line][columns] != '1'
				&& line == game->map_h - 1) ||
				(game->file_data[line][columns] != '1'
				&& columns == game->map_l - 1))
				put_error_message(4);
			columns++;
		}
		line++;
	}
}
