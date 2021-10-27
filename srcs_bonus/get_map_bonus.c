/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:40:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:10:08 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_map_height(char *file, t_data **game)
{
	(*game)->map_h = get_lines_height(file);
}

void	get_map_length(char *file, t_data **game)
{
	(*game)->map_l = get_line_length(file);
}

// int	ft_reading_file(char *file, t_data **game)
// {
// 	int		rd;
// 	int		fd;
// 	int		line;

// 	line = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	init_array(file, game);
// 	rd = get_next_line(fd, &(*game)->file_data[line]);
// 	while (rd == 1)
// 	{
// 		line++;
// 		rd = get_next_line(fd, &(*game)->file_data[line]);
// 	}
// 	close (fd);
// 	check_wall(*game);
// 	return (1);
// }

int	ft_reading_file(char *file, t_data **game)
{
	int		fd;
	int		line;
	char	*line_buf;

	line = 0;
	line_buf = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	init_array(file, game);
	while (get_next_line(fd, &line_buf))
	{
		if (line_buf)
		{
			(*game)->file_data[line] = ft_strdup(line_buf);
			free (line_buf);
			line++;
		}
	}
	if (line_buf)
		free (line_buf);
	close (fd);
	check_wall(*game);
	return (1);
}
