#include "fractol.h"

void			ft_fractale_man(t_frac *f)
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
				f->iz = 2 * f->iz * tmp + f->ic;
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}

void			ft_fractale_jul(t_frac *f)
{
	float		tmp;

	f->x = -1;
	while (++f->x < WID)
	{
		f->y = 0;
		while (++f->y < LEN)
		{
			f->rz = f->x / f->zoom + f->x1;
			f->iz = f->y / f->zoom + f->y1;
			f->a = 0;
			while (f->a < f->i && f->rz * f->rz + f->iz * f->iz < 4)
			{
				tmp = f->rz;
				f->rz = f->rz * f->rz - f->iz * f->iz + f->rc;
				f->iz = 2 * f->iz * tmp + f->ic;
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}

void			ft_fractale_bship(t_frac *f)
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
				f->rz = fabs(f->rz * f->rz - f->iz * f->iz + f->rc);
				f->iz = fabs(2 * f->iz * tmp + f->ic);
				f->a++;
			}
			ft_put_pixel(f->x, f->y, f);
		}
	}
}

static float	ft_calcul(t_frac *f, float tmp)
{
	float		rz;
	float		iz;
	float		x;
	float		r;

	r = f->rz;
	rz = f->rz * f->rz;
	iz = f->iz * f->iz;
	x = rz - iz;
	tmp = 3.0 * (x * x + 4.0 * rz * iz);
	if (tmp == 0.0)
		tmp = 0.000001;
	f->rz = (2.0 / 3.0) * r + x / tmp;
	f->iz = (2.0 / 3.0) * f->iz - 2.0 * r * f->iz / tmp;
	return (tmp);
}

void			ft_fractale_newton(t_frac *f, float tmp)
{
	f->x = -1;
	while (++f->x < WID)
	{
		f->y = 0;
		while (++f->y < LEN)
		{
			f->rz = f->x / f->zoom + f->x1;
			f->iz = f->y / f->zoom + f->y1;
			f->a = -1;
			tmp = 1;
			while (++f->a < f->i)
				tmp = ft_calcul(f, tmp);
			ft_put_pixel_color(f->x, f->y, f);
		}
	}
}
