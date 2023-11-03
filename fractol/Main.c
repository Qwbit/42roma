/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:24:31 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/03 22:58:41 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_init(t_fractal *fractal, t_render *render)
{
    fractal->movement.Color = 0;
    fractal->iteration = 0;
    fractal->vector = 0;
    fractal->movement.Speed = 0;
    fractal->movement.Scale = 1;
    fractal->mlx_connection = mlx_init();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, "fractol");
    render->image = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    render->data = mlx_get_data_addr(render->image, &render->bpp, &render->size_line, &render->endian);
    fractal->render = render;
    
}

int ft_select_fractal(t_fractal *fractal, int argc, char *argv[])
{
    if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        fractal->Select = 0;
    else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
    {

        if (argc == 4 && argv[2] != NULL && argv[3] != NULL)
        {
            fractal->JuliaX = ft_atodbl(argv[2]);
            fractal->JuliaY = ft_atodbl(argv[3]);
            fractal->Select = 1;
        }
    }
    else
    {
        ft_putstr_fd("Error\n", 0);
        exit(EXIT_FAILURE);
    }
    return (0);
}

int main(int ac, char *av[])
{
    t_fractal fractal;
    t_render render;



    ft_select_fractal(&fractal, ac, av);
    ft_init(&fractal, &render);
    ft_iteration(&fractal, &render);
    mlx_put_image_to_window(fractal.mlx_connection, fractal.mlx_window, render.image, 0, 0);
    mlx_hook(fractal.mlx_window, 2, 1L << 0, key_hook, &fractal);
    mlx_hook(fractal.mlx_window, 6, 1L << 6, mouse_move_hook, &fractal);
    mlx_hook(fractal.mlx_window, 4, 1L << 2, mouse_button_hook, &fractal);
    mlx_hook(fractal.mlx_window, 17, 0, close_window, &fractal);
    mlx_loop(fractal.mlx_connection);
}