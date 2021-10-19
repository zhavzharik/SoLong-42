/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:29:53 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 19:37:00 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_visual *window)
{
	(void)keycode;
	(void)window;
	printf("Hello from keyhook!\n");
	return (0);
}

void	hook_test(t_visual **window)
{
	mlx_key_hook((*window)->win_ptr, key_hook, window);
	// mlx_hook((*window)->win_ptr, 2, 1L << 0, close, &window);
	mlx_loop((*window)->mlx_ptr);
}

// int	close(int keycode, t_visual *window)
// {
// 	(void)keycode;
// 	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
// 	return (0);
// }
