/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:11:54 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 22:35:05 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_err_str(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
}

void	put_error_message(int check)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (check == 1)
		put_err_str("The map must be rectangular");
	else if (check == 2)
		put_err_str("The map must have at least one exit,\
			one collectible, and one starting position");
	else if (check == 3)
		put_err_str("The map must contain only 01CEP characters");
	else if (check == 4)
		put_err_str("The map must be closed/surrounded by walls");
	exit (0);
}
