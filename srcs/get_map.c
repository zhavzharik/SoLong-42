/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:40:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/15 22:38:55 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static size_t	get_map_height(char *file)
{
	int		rd;
	int		fd;
	char	*line;
	size_t	size;

	size = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rd = 1;
	while (get_next_line(fd, &line))
	{
		if (line)
			free(line);
		size++;
	}
	if (line)
		free(line);
	close (fd);
	return (size);
}

int	ft_reading_file(char *file, t_data **game)
{
	int		rd;
	int		fd;
	size_t	size;

	size = get_map_height(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	(*game)->file_data = malloc(sizeof(char **) * (size + 1));
	if (!((*game)->file_data))
		return (0);
	rd = get_next_line(fd, &(*game)->file_data[(*game)->map_h]);
	while (rd == 1)
	{
		(*game)->map_l = ft_strlen((*game)->file_data[(*game)->map_h]);
		(*game)->map_h += 1;
		rd = get_next_line(fd, &(*game)->file_data[(*game)->map_h]);
	}
	close (fd);
	return (0);
}
