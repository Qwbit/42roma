/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:00 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/03 23:02:41 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->render->image);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_press(int keycode, t_fractal *fractal)
{
   // printf("%d\n", keycode);
    if (keycode == 65453 || keycode == 45)
        fractal->movement.Scale = fractal->movement.Scale * 2;
    if (keycode == 65451 || keycode == 43)
        fractal->movement.Scale = fractal->movement.Scale * 0.5;
    if (keycode == 65361)
        fractal->movement.Horizontal = fractal->movement.Horizontal - (0.5 * fractal->movement.Scale);
    if (keycode == 65362)
        fractal->movement.Vertical = fractal->movement.Vertical - (0.5 * fractal->movement.Scale);
    if (keycode == 65363)
        fractal->movement.Horizontal = fractal->movement.Horizontal + (0.5 * fractal->movement.Scale);
    if (keycode == 65364)
        fractal->movement.Vertical = fractal->movement.Vertical + (0.5 * fractal->movement.Scale);
    if (keycode == 105)
        fractal->movement.Iteration = fractal->movement.Iteration + 10;
    if (keycode == 117)
        fractal->movement.Iteration = fractal->movement.Iteration - 10;
    if (keycode == 115)
        fractal->movement.Speed = fractal->movement.Speed + 1;
    return(0);
}

int key_hook(int keycode, t_fractal *fractal)
{

    if (keycode == 65307)
        close_window(fractal);
    if (keycode == 99)
    {
        fractal->movement.Color = fractal->movement.Color + 1;
        if (fractal->movement.Color >= 63)
            fractal->movement.Color = 0;

        printf("iteration:%d\n", (fractal->iteration));
        printf("movement.color:%d\n", (fractal->movement.Color));
        printf("iter+color:%d\n", (fractal->iteration + fractal->movement.Color));
    }
    key_press(keycode, fractal);
    ft_iteration(fractal, fractal->render);
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->render->image, 0, 0);
    return (0);
}

int mouse_move_hook(int x, int y, t_fractal *fractal)
{

    (void)x;
    (void)y;
    char *str;
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->render->image, 0, 0);
    str = ("ARROW FOR MOVEMENT");
    mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - ((WIDTH / 20) * 19), HEIGHT - (HEIGHT / 20) * 19, 0xFFFFFF, str);
    str = ("i/u: increase/decrease iteration");
    mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - (WIDTH / 20) * 19, HEIGHT - (HEIGHT / 20) * 19 + 20, 0xFFFFFF, str);
    str = ("s: increase speed of vector");
    mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - (WIDTH / 20) * 19, HEIGHT - (HEIGHT / 20) * 19 + 40, 0xFFFFFF, str);
    str = ("c: change color");
    mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - (WIDTH / 20) * 19, HEIGHT - (HEIGHT / 20) * 19 + 60, 0xFFFFFF, str);
    str = ("+ or -: zoom");
    mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - (WIDTH / 20) * 19, HEIGHT - (HEIGHT / 20) * 19 + 80, 0xFFFFFF, str);
    str = ("Mouse Wheel Button: change julia C");
    mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - (WIDTH / 20) * 19, HEIGHT - (HEIGHT / 20) * 19 + 100, 0xFFFFFF, str);
    
    return (0);
}

int ft_Mouse_Scale(int button, int x, int y, t_fractal *fractal)
{
    double X;
    double Y;

    X = (fractal->movement.Horizontal + (map(x, -2, 2, 0, WIDTH) * fractal->movement.Scale));
    Y = (fractal->movement.Horizontal + (map(y, 2, -2, 0, WIDTH) * fractal->movement.Scale));
    if (button == 1)
    {
        fractal->movement.Scale = fractal->movement.Scale * 0.5;
        fractal->movement.Horizontal = X - 0.5 * (WIDTH / HEIGHT) * fractal->movement.Scale;
        fractal->movement.Vertical = Y - 0.5 * fractal->movement.Scale;
    }
    if (button == 3)
    {
        fractal->movement.Horizontal = X - (0.5 * WIDTH / HEIGHT) * fractal->movement.Scale;
        fractal->movement.Vertical = Y - (0.5 * WIDTH / HEIGHT) * fractal->movement.Scale;
        fractal->movement.Scale = fractal->movement.Scale * 2;
    }
    return (0);
}

int mouse_button_hook(int button, int x, int y, t_fractal *fractal)
{
   
    if(button == 2)
    {
    fractal->JuliaX = map(x, -2, 2, 0, WIDTH);
    fractal->JuliaY = map(y, -2, 2, 0, HEIGHT);
    }
  
    ft_Mouse_Scale(button, x, y, fractal);
    
    ft_iteration(fractal, fractal->render);
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->render->image, 0, 0);
    return (0);
}
