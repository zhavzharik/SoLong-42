/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:40:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/18 14:20:36 by abridger         ###   ########.fr       */
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

int	ft_reading_file(char *file, t_data **game)
{
	int		rd;
	int		fd;
	int		line;

	line = 0;
	get_map_height(file, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	(*game)->file_data = malloc(sizeof(char **) * ((*game)->map_h + 1));
	if (!((*game)->file_data))
		return (0);
	rd = get_next_line(fd, &(*game)->file_data[line]);
	while (rd == 1)
	{
		(*game)->map_l = ft_strlen((*game)->file_data[line]);
		line++;
		rd = get_next_line(fd, &(*game)->file_data[line]);
	}
	close (fd);
	return (1);
}
