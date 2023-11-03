/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:16:54 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/03 22:45:31 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_fractal ft_mandelbrot_set(t_fractal *fractal, t_render *render)
{
    fractal->iteration = 0;
    fractal->z.x = 0;
    fractal->z.y = 0;
    fractal->c.x = fractal->movement.Horizontal + (map(render->x, -2, 2, 0, WIDTH) * fractal->movement.Scale);
    fractal->c.y = fractal->movement.Vertical + (map(render->y, 2, -2, 0, HEIGHT) * fractal->movement.Scale);
    
    while (fractal->iteration < ITERATIONS + fractal->movement.Iteration)
    {
        fractal->z_result = ft_comp_sum(ft_comp_pow(fractal->z), fractal->c);
        fractal->vector = ft_vector_lenght(fractal->z, fractal->z_result);
        if (fractal->vector > (SPEED + fractal->movement.Speed))
            return (*fractal);
        fractal->z = fractal->z_result;
        fractal->iteration++;
    }
    
    return (*fractal);
}

t_fractal ft_julia_set(t_fractal *fractal, t_render *render)
{
    fractal->iteration = 0;
    fractal->c.x = fractal->JuliaX;
    fractal->c.y = fractal->JuliaY;
    fractal->z.x = fractal->movement.Horizontal + (map(render->x, -2, 2, 0, WIDTH) * fractal->movement.Scale);
    fractal->z.y = fractal->movement.Vertical + (map(render->y, 2, -2, 0, HEIGHT) * fractal->movement.Scale);
    
    while (fractal->iteration < ITERATIONS + fractal->movement.Iteration)
    {
        fractal->z_result = ft_comp_sum(ft_comp_pow(fractal->z), fractal->c);
        fractal->vector = ft_vector_lenght(fractal->z, fractal->z_result);
        if (fractal->vector > (SPEED + fractal->movement.Speed))
            return (*fractal);
        fractal->z = fractal->z_result;
        fractal->iteration++;
    }
    
    return (*fractal);
}

