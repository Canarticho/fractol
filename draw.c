#include "fractol.h"

void		ft_put_pixel(int x, int y, t_frac *f)
{
	int		*i;
	int		t;

	if (y < LEN && x < WID && x > 0 && y > 0)
	{
		t = x * 4 + y * f->sline;
		i = (int *)&f->data[t];
		if (f->a == f->i)
			*i = 0x000000;
		else
		{
			if (f->ft == 6)
				*i = 0x0000FF + (100000000 * f->a) / 70;
			else
				*i = 0x8A0808 + (0x0000FF - f->a);
		}
	}
}

void		ft_put_pixel_color(int x, int y, t_frac *f)
{
	int		*i;
	int		t;

	if (y < LEN && x < WID && x > 0 && y > 0)
	{
		t = x * 4 + y * f->sline;
		i = (int *)&f->data[t];
		if (f->rz > 0)
			*i = 0xFF0000;
		else if ((f->rz < -0.3) && (f->iz > 0))
			*i = 0x00FF00;
		else
			*i = 0x0000FF;
	}
}

void		ft_menu(t_frac *f)
{
	int x;

	x = WID - 285;
	mlx_string_put(f->mlx, f->win, x, 80, 0XFFFFFF, "Zoom: +/-");
	mlx_string_put(f->mlx, f->win, x, 100, 0XFFFFFF, "Iteration: 1/4");
	mlx_string_put(f->mlx, f->win, x, 120, 0XFFFFFF, "Reset: 2");
	mlx_string_put(f->mlx, f->win, x, 140, 0XFFFFFF, "Change: 3/6");
}

void		ft_fractale(t_frac *f)
{
	if (f->ft == 1)
		ft_fractale_man(f);
	else if (f->ft == 2)
		ft_fractale_jul(f);
	else if (f->ft == 3)
		ft_fractale_bship(f);
	else if (f->ft == 4)
		ft_fractale_man2(f, 0, 0, 0);
	else if (f->ft == 5)
		ft_fractale_man4(f, 0, 0, 0);
	else if (f->ft == 6)
		ft_fractale_newton_love(f, 0);
	else if (f->ft == 7)
		ft_fractale_newton(f, 0);
	else if (f->ft == 8)
		ft_fractale_tricorn(f);
	else
		ft_fractale_mandelbar4(f, 0, 0, 0);
}

int			ft_draw(t_frac *f)
{
	f->img = mlx_new_image(f->mlx, WID, LEN);
	f->data = mlx_get_data_addr(f->img, &f->bpp, &f->sline, &f->endian);
	ft_fractale(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	ft_menu(f);
	mlx_destroy_image(f->mlx, f->img);
	return (0);
}
