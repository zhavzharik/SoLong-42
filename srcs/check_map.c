/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:50:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 22:32:01 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	get_line_length(char *file)
{
	int		rd;
	int		fd;
	char	*line;
	size_t	len;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (0);
	rd = 1;
	while (get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	close (fd);
	return (len);
}

void	check_map_length(char *file)
{
	int		rd;
	int		fd;
	char	*line;
	size_t	len;
	size_t	tmp;

	len = get_line_length(file);
	tmp = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (0);
	rd = 1;
	while (get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		if (line)
			free(line);
		if (len != tmp)
			put_error_message(1);
	}
	if (line)
		free(line);
	close (fd);
}
