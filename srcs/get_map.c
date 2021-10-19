/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:40:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 13:57:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_height(char *file, t_data **game)
{
	int		rd;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (0);
	rd = 1;
	while (get_next_line(fd, &line))
	{
		if (line)
			free(line);
		(*game)->map_h++;
	}
	if (line)
		free(line);
	close (fd);
}

void	get_map_length(char *file, t_data **game)
{
	int		rd;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (0);
	rd = 1;
	while (get_next_line(fd, &line))
	{
		(*game)->map_l = ft_strlen(line);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	close (fd);
}

int	ft_reading_file(char *file, t_data **game)
{
	int		rd;
	int		fd;
	int		line;

	line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	init_array(file, game);
	rd = get_next_line(fd, &(*game)->file_data[line]);
	while (rd == 1)
	{
		line++;
		rd = get_next_line(fd, &(*game)->file_data[line]);
	}
	close (fd);
	return (1);
}
