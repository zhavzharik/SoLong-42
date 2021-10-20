/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:29:53 by abridger          #+#    #+#             */
/*   Updated: 2021/10/20 22:28:58 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_visual *window)
{
	(void)window;
	if (keycode == XK_W)
		printf("Hello from keyhook press W!\n");
	else if (keycode == XK_S)
		printf("Hello from keyhook press S!\n");
	else if (keycode == XK_A)
		printf("Hello from keyhook press A!\n");
	else if (keycode == XK_D)
		printf("Hello from keyhook press D!\n");
	return (0);
}

void	hook_test(t_visual **window)
{
	mlx_key_hook((*window)->win_ptr, key_hook, window);
	// mlx_hook((*window)->win_ptr, 2, 1L << 0, close, window);
	// mlx_loop((*window)->mlx_ptr);
}

// int	close(void *param)
// {
// 	(void) param;
// 	exit (0);
// }

int	key_press(int key, t_data **game, t_visual **window, t_action *func)
{
	if (key == XK_W)
		move_up(key, game, window, func);
	else if (key == XK_S)
		move_down(key, game, window, func);
	else if (key == XK_A)
		move_left(key, game, window, func);
	else if (key == XK_D)
		move_right(key, game, window, func);
	return (0);
}

void	setup_action(t_data **game, t_visual **window)
{
	mlx_hook((*window)->win_ptr, 2, 0, key_press, game);
	mlx_hook((*window)->win_ptr, 17, 0, close, window);
}
