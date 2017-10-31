/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlf-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 02:39:28 by chlf-van          #+#    #+#             */
/*   Updated: 2017/10/31 20:58:17 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mouse_zoom(int key, int x, int y, t_frac *f)
{
	double	tmpx;
	double	tmpy;

	tmpx = x / f->zoom + f->x1;
	tmpy = y / f->zoom + f->y1;
	if (key == IN || key == OUT)
		f->zoom = (key == IN) ? (f->zoom / 1.1) : (f->zoom * 1.1);
	if (key == CG || key == CD)
		f->zoom = (key == CD) ? (f->zoom / 1.1) : (f->zoom * 1.1);
	f->x1 = tmpx - (x / f->zoom);
	f->y1 = tmpy - (y / f->zoom);
	return (0);
}

int			ft_mouse(int x, int y, t_frac *f)
{
	f->mx = x;
	f->my = y;
	if (x < WID && x > 0 && y < LEN && y > 0 && !f->lock)
	{
		f->rc = (float)(x + 400 - WID) / 500;
		f->ic = (float)(y + 400 - LEN) / 500;
	}
	return (0);
}

static void	ft_move(int key, t_frac *f)
{
	if (key == ESP)
	{
		if (!f->lock)
			f->lock = 1;
		else
			f->lock = 0;
	}
	if (key == UP || key == W)
		f->y1 += 0.1;
	if (key == DOWN || key == S)
		f->y1 -= 0.1;
	if (key == LEFT || key == A)
		f->x1 += 0.1;
	if (key == RIGHT || key == D)
		f->x1 -= 0.1;
}

static void	ft_zoom(int key, t_frac *f)
{
	double	tmpx;
	double	tmpy;

	tmpx = f->mx / f->zoom + f->x1;
	tmpy = f->my / f->zoom + f->y1;
	f->zoom = (key == PLUS) ? (f->zoom * 1.1) : (f->zoom / 1.1);
	f->x1 = tmpx - (f->mx / f->zoom);
	f->y1 = tmpy - (f->my / f->zoom);
}

int			ft_keypress(int key, t_frac *f)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == W
			|| key == A || key == S || key == D || key == ESP)
		ft_move(key, f);
	if (key == PLUS || key == MOIN)
		ft_zoom(key, f);
	f->i += (key == N_ITERATION) ? 5 : 0;
	f->i -= (key == P_ITERATION) ? 5 : 0;
	(key == RESET) ? ft_init(f) : 0;
	if (key == NEXT || key == PREV)
	{
		if (key == NEXT)
			f->ft = (f->ft == 9) ? (1) : (f->ft + 1);
		else
			f->ft = (f->ft == 1) ? (9) : (f->ft - 1);
		ft_init(f);
	}
	(key == ESC) ? exit(2) : 0;
	return (0);
}
