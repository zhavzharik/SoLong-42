/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:11:54 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:09:53 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_err_str(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
}

void	put_error_message(int check)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (check == 1)
		put_err_str("The map must be rectangular!");
	else if (check == 2)
		put_err_str("The map must have at least one exit ('E')!");
	else if (check == 3)
		put_err_str("The map must contain only '01CEP' characters!");
	else if (check == 4)
		put_err_str("The map must be closed/surrounded by walls!");
	else if (check == 5)
		put_err_str("The map must be in format *.ber");
	else if (check == 6)
		put_err_str("The map must have one player ('P')!");
	else if (check == 7)
		put_err_str("The map must have at least one collectible ('C')!");
	else if (check == 8)
		put_err_str("The wrong number of arguments!");
	else if (check == 9)
		put_err_str("File reading error!");
	exit (EXIT_FAILURE);
}
