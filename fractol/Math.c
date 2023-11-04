/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:36:49 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/04 18:06:20 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex ft_comp_sum(t_complex z1, t_complex z2)
{
    t_complex z_result;
    z_result.x = z1.x + z2.x;
    z_result.y = z1.y + z2.y;
    return (z_result);
}

t_complex ft_comp_mult(t_complex z1, t_complex z2)
{
    t_complex z_result;
    z_result.x = (z1.x * z2.x - z1.y * z2.y);
    z_result.y = (z1.x * z2.y + z1.y * z2.x);
    return(z_result);
}

t_complex ft_comp_pow(t_complex z)
{
    t_complex z_result;
    z_result.x = (z.x * z.x) - (z.y * z.y);
    z_result.y = 2 * (z.x * z.y);
    return (z_result);
}

double ft_vector_lenght(t_complex z1, t_complex z2)
{
    double vector_lenght;
    vector_lenght = sqrt(((z1.x - z2.x) * (z1.x - z2.x)) + ((z1.y - z2.y) * (z1.y - z2.y)));
    return (vector_lenght);
}



t_fractal ft_iteration(t_fractal *fractal, t_render *render)
{
    render->x = 0;
    render->y = 0;

    while (render->x < WIDTH)
    {
        while (render->y < HEIGHT)
        {
            if(fractal->Select == 1)
            ft_julia_set(fractal, render);
            else if(fractal->Select == 2)
            ft_burningship_set(fractal, render);
            else
            ft_mandelbrot_set(fractal, render);
            ft_store_pixel(fractal, render);
            render->y += 1;
        }
        render->y = 0;
        render->x += 1;
    }
    return (*fractal);
}





