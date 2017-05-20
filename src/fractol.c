/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 14:52:30 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/11/13 18:47:57 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		ft_error(char *str)
{
	if (*str == 0)
		ft_putendl_fd("fract_ol: Undefined error", 2);
	else
		ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

static void		init_var(t_env *e)
{
	e->zoom = 1;
	e->move_x = 0;
	e->move_y = 0;
	e->max_i = 300;
	e->max_r = 4;
	e->max_l = 2;
	e->mod_n = 0;
	e->c1 = -0.7;
	e->c2 = 0.27015;
	e->color_coeff = 2;
	e->freeze = 0;
}

static void		init_prog(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_error("");
	e->win = mlx_new_window(e->mlx, S_W, S_H, "fract_ol");
	init_var(e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_hook(e->win, 6, 64, motion_hook, e);
	mlx_hook(e->win, 4, 5, button_hook, e);
	mlx_expose_hook(e->win, exposed, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}

static void		check_input(t_env *e, char *arg, char *usage)
{
	if (ft_strequ(arg, "man"))
		e->id = 1;
	else if (ft_strequ(arg, "jul"))
		e->id = 2;
	else if (ft_strequ(arg, "shi"))
		e->id = 3;
	else if (ft_strequ(arg, "mod"))
		e->id = 4;
	else if (ft_strequ(arg, "sie"))
		e->id = 5;
	else
	{
		ft_putendl_fd("Wrong arg.", 2);
		ft_error(usage);
	}
}

int				main(int ac, char **av)
{
	t_env	*e;
	char	*usage;

	usage = "usage: ./fractol [man, jul, shi, sie] \
(Mandelbrot, Julia, Ship, Sierpinski)";
	if (ac != 2)
	{
		ac < 2 ? ft_putendl_fd("Not enough args.", 2) : \
		ft_putendl_fd("Too many args.", 2);
		ft_error(usage);
	}
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_error("");
	check_input(e, av[1], usage);
	init_prog(e);
	return (0);
}
