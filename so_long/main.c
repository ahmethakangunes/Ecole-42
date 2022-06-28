/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:37:52 by agunes           #+#    #+#             */
/*   Updated: 2022/04/18 14:39:13 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *main)
{
	mlx_destroy_image(main->mlx, main->player);
	mlx_destroy_image(main->mlx, main->wall);
	mlx_destroy_image(main->mlx, main->exit);
	mlx_destroy_image(main->mlx, main->coll);
	mlx_destroy_window(main->mlx, main->win);
	free(main->map);
	free(main);
}

int	move(int keycode, t_list *main)
{
	if (keycode == 13 || keycode == 126)
		moveup(main);
	if (keycode == 1 || keycode == 125)
		movedown(main);
	if (keycode == 2 || keycode == 124)
		moveright(main);
	if (keycode == 0 || keycode == 123)
		moveleft(main);
	if (keycode == 53)
	{
		ft_free(main);
		printf("%sElif gülsüz kaldı.... !\n", "\x1B[31m");
		exit (0);
		return (0);
	}
	mlx_clear_window(main->mlx, main->win);
	putimage(main);
	ft_printf("Adım sayısı = %d\n", main->movecount + 1);
	if (main->movecount > 498)
	{
		ft_free(main);
		ft_printf("%sElif gülsüz kaldı.... !\n", "\x1B[31m");
		exit (0);
	}
	return (1);
}

int	bercheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b' || \
		s[i - 4] != '.' || i < 5)
	{
		ft_printf("%sWrong file name!\n", "\x1B[31m");
		return (0);
	}
	return (1);
}

int	xbutton(t_list *main)
{
	(void)main;
	ft_free(main);
	ft_printf("%sGAME OVER !\n", "\x1B[31m");
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*main;

	if (ac == 2)
	{
		if (!bercheck(av[1]))
			return (0);
		main = malloc(sizeof(t_list));
		if (!main)
			return (0);
		if (!(createmap(main, av[1])))
		{
			free(main);
			return (0);
		}
		mlx_hook(main->win, 2, 1L << 0, move, main);
		mlx_hook(main->win, 17, 0, &xbutton, main);
		mlx_loop(main->mlx);
	}
	else
	{
		ft_printf("%sError\n", "\x1B[31m");
		exit(0);
	}
}
