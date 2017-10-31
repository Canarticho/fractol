/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 00:44:11 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/31 20:55:23 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_init(t_frac *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WID, LEN, "Fractol");
	f->img = mlx_new_image(f->mlx, WID, LEN);
	f->data = mlx_get_data_addr(f->img, &f->bpp, &f->sline, &f->endian);
	mlx_hook(f->win, 2, 3, &ft_keypress, f);
	mlx_hook(f->win, 6, 7, &ft_mouse, f);
	mlx_mouse_hook(f->win, &ft_mouse_zoom, f);
	mlx_loop_hook(f->mlx, &ft_draw, f);
	mlx_loop(f->mlx);
}

void	ft_init(t_frac *f)
{
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->i = 25;
	f->zoom = 100;
	f->rc = 0.285;
	f->ic = 0.01;
	f->lock = 0;
}

int		main(int ac, char **av)
{
	t_frac f;

	if (ac == 2 && ft_strlen(av[1]) == 1 && ft_strchr("123456789", *av[1]) &&
			(f.ft = (int)(*av[1] - '0')) < 10 && f.ft > 0)
	{
		ft_init(&f);
		ft_mlx_init(&f);
	}
	else
	{
		ft_putstr("usage : ./fractol fractol_type\n1 : Mandelbrot.\n");
		ft_putstr("2 : Julia.\n3 : Burning Ship.\n4 : Mandelbrot p3.\n");
		ft_putstr("5 : Mandelbrot p4.\n6 : Newton Love.\n7 : Newton.\n");
		ft_putstr("8 : Mandelbar.\n9 : Mandelbar 4.\n");
	}
	return (0);
}
