/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:25 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/03 23:07:25 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void pixel_put(t_render *render, int c)
{
    char *dst;

    dst = render->data + (render->y * render->size_line + render->x * (render->bpp / 8));
    *(unsigned int *)dst = c;
}

void ft_store_pixel(t_fractal *fractal, t_render *render)
{
    int colors[64] = {
    0x0000FF, 0x0011FF, 0x0022FF, 0x0033FF, 0x0044FF, 0x0055FF, 0x0066FF, 0x0077FF,
    0x0088FF, 0x0099FF, 0x00AAFF, 0x00BBFF, 0x00CCFF, 0x00DDFF, 0x00EEFF, 0x00FFFF,
    0x00DDFF, 0x00CCFF, 0x00BBFF, 0x00AAFF, 0x0099FF, 0x0088FF, 0x0077FF, 0x0066FF,
    0x0055FF, 0x0044FF, 0x0033FF, 0x0022FF, 0x0011FF, 0x0000FF, 0x001100, 0x002200,
    0x003300, 0x004400, 0x005500, 0x006600, 0x007700, 0x008800, 0x009900, 0x00AA00,
    0x00BB00, 0x00CC00, 0x00DD00, 0x00EE00, 0x00FF00, 0x11FF00, 0x22FF00, 0x33FF00,
    0x44FF00, 0x55FF00, 0x66FF00, 0x77FF00, 0x88FF00, 0x99FF00, 0xAAFF00, 0xBBFF00,
    0xCCFF00, 0xDDFF00, 0xEEFF00, 0xFFFF00
    };

    if (fractal->vector < (SPEED + fractal->movement.Speed))
        pixel_put(render, 0x000000);

    else
    {

        pixel_put(render, colors[(fractal->iteration + fractal->movement.Color) % 16]);
    }
}



