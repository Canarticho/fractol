/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:08:26 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/31 19:53:10 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fractale_man2(t_frac *f, float tmp, float rz, float iz)
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
				rz = f->rz * f->rz;
				iz = f->iz * f->iz;
				f->rz = rz * f->rz - 3 * f->rz * iz + f->rc;
				f->iz = 3 * rz * f->iz - iz * f->iz + f->ic;
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}

void		ft_fractale_man4(t_frac *f, float tmp, float rz, float iz)
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
				rz = tmp * tmp;
				iz = f->iz * f->iz;
				f->rz = rz * rz - 6 * rz * iz + iz * iz + f->rc;
				f->iz = 4 * rz * tmp * f->iz - 4 * tmp * iz * f->iz + f->ic;
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}
