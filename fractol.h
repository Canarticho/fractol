/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 00:47:28 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/31 20:56:25 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <mlx.h>

# define LEN 1050
# define WID 1600

# define RESET 84
# define W 13
# define A 0
# define S 1
# define D 2
# define MOIN 78
# define PLUS 69
# define PREV 88
# define NEXT 85
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define N_ITERATION 86
# define P_ITERATION 83
# define ESC 53
# define IN 5
# define OUT 4
# define BLOC 85
# define ESP 49

# define CG 1
# define CD 2

typedef struct	s_frac
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	float		zoom;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		rc;
	float		ic;
	float		rz;
	float		iz;
	int			mx;
	int			my;
	int			bpp;
	int			sline;
	int			endian;
	int			x;
	int			y;
	int			a;
	int			i;
	int			ft;
	int			lock;

}				t_frac;

int				ft_keypress(int key, t_frac *f);
int				ft_mouse_zoom(int key, int x, int y, t_frac *f);
int				ft_mouse(int x, int y, t_frac *f);
int				ft_draw(t_frac *f);
void			ft_put_pixel(int x, int y, t_frac *f);
void			ft_put_pixel_color(int x, int y, t_frac *f);
void			ft_init(t_frac *f);
void			ft_fractale_man(t_frac *f);
void			ft_fractale_man2(t_frac *f, float tmp, float rz, float iz);
void			ft_fractale_man4(t_frac *f, float tmp, float rz, float iz);
void			ft_fractale_jul(t_frac *f);
void			ft_fractale_bship(t_frac *f);
void			ft_fractale_newton(t_frac *f, float tmp);
void			ft_fractale_mandelbar4(t_frac *f, float tm, float rx, float iz);
void			ft_fractale_tricorn(t_frac *f);
void			ft_fractale_newton_love(t_frac *f, float tmp);
#endif
