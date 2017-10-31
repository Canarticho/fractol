/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:07:31 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/31 19:52:49 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_fractale_mandelbar4(t_frac *f, float tmp, float rz, float iz)
{
	f->x = -1;
	while (++f->x < WID)
	{
		f->y = 0;
		while (++f->y < LEN)
		{
			f->rc = f->x / f->zoom + f->x1;
			f->ic = f->y / f->zoom + f->y1;
			f->rz = 0;
			f->iz = 0;
			f->a = 0;
			while (f->a < f->i && f->rz * f->rz + f->iz * f->iz < 4)
			{
				tmp = f->rz;
				iz = f->iz * f->iz;
				rz = f->rz * f->rz;
				f->rz = rz * f->rz - 3 * f->rz * iz + f->rc;
				f->iz = -(3 * rz * f->iz - iz * f->iz) + f->ic;
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}

void			ft_fractale_tricorn(t_frac *f)
{
	float		tmp;

	f->x = -1;
	while (++f->x < WID)
	{
		f->y = 0;
		while (++f->y < LEN)
		{
			f->rc = f->x / f->zoom + f->x1;
			f->ic = f->y / f->zoom + f->y1;
			f->rz = 0;
			f->iz = 0;
			f->a = 0;
			while (f->a < f->i && f->rz * f->rz + f->iz * f->iz < 4)
			{
				tmp = f->rz;
				f->rz = f->rz * f->rz - f->iz * f->iz + f->rc;
				f->iz = -(2 * f->iz * tmp) + f->ic;
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}

static float	ft_calcul(t_frac *f, float tmp)
{
	float		r;
	float		i;
	float		rz;
	float		iz;

	r = f->rz;
	i = f->iz;
	rz = f->rz * f->rz;
	iz = f->iz * f->iz;
	tmp = (rz + iz) * (rz + iz);
	f->rz = (2 * tmp * rz * f->rz - iz) / (3 * tmp);
	f->iz = (2 * f->iz * (tmp - r)) / (3 * tmp);
	tmp = (f->rz - r) * (f->rz - r) + (f->iz - i) * (f->iz - i);
	return (tmp);
}

void			ft_fractale_newton_love(t_frac *f, float tmp)
{
	f->x = -1;
	while (++f->x < WID)
	{
		f->y = 0;
		while (++f->y < LEN)
		{
			f->rz = f->x / f->zoom + f->x1;
			f->iz = f->y / f->zoom + f->y1;
			f->a = 0;
			tmp = 1;
			while (f->a < f->i && tmp > 0.000001)
			{
				tmp = ft_calcul(f, tmp);
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}
