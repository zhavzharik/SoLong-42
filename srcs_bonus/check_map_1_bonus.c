/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:50:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:08:34 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

size_t	get_lines_height(char *file)
{
	int		fd;
	char	*line;
	size_t	height;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while (get_next_line(fd, &line))
	{
		if (line)
			free(line);
		height++;
	}
	if (line)
		free(line);
	close (fd);
	return (height);
}

size_t	get_line_length(char *file)
{
	int		fd;
	char	*line;
	size_t	len;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
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
	int		fd;
	char	*line;
	size_t	len;
	size_t	tmp;

	tmp = get_line_length(file);
	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
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

void	check_file_name(char *file)
{
	const char	*dot;
	size_t		len;

	len = ft_strlen(file);
	dot = (const char *) &file[len - 4];
	if (ft_strncmp(dot, ".ber", 4) != 0)
		put_error_message(5);
}

void	check_data(char *file)
{
	check_map_length(file);
	check_file_name(file);
	check_map_character(file);
}
