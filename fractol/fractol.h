/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:59:13 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/03 23:56:55 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compile

cc fractol.c minilibx-linux/libmlx.a -lX11 -lXext -lm -o fractol
*/

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "fractol.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR_MESSAGE "Write mandelbrot for the mandelbrot set\nor \njulia <real> <imaginary> for the julia set\n"
#define WIDTH 800
#define HEIGHT 800
#define ITERATIONS 10
#define SPEED 4

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

typedef struct s_movement
{
	double 	Horizontal;
	double 	Vertical;
	double 	Iteration;
	int 	Color;
	double 	Speed;
	double 	Scale;
} t_movement;

typedef struct s_render
{
	void 	*image;
	void 	*data;
	int 	x;
	int 	y;
	int 	color;
	int 	bpp;
	int 	size_line;
	int 	endian;
	int     palette[];
} t_render;

typedef struct s_fractal
{
	t_complex c;
	t_complex z;
	t_complex z_result;
	int Select;
	double JuliaX;
	double JuliaY;
	int iteration;
	double vector;
	void *mlx_connection;
	void *mlx_window;
	t_render *render;
	t_movement movement;
} t_fractal;

t_complex ft_comp_sum(t_complex z1, t_complex z2);
t_complex ft_comp_mult(t_complex z1, t_complex z2);
t_complex ft_comp_pow(t_complex z);
t_fractal ft_mandelbrot_set(t_fractal *fractal, t_render *render);
t_fractal ft_julia_set(t_fractal *fractal, t_render *render);
double ft_vector_lenght(t_complex z1, t_complex z2);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_fractal ft_iteration(t_fractal *fractal, t_render *render);
void pixel_put(t_render *r, int c);
void ft_store_pixel(t_fractal *fractal, t_render *render);


int close_window(t_fractal *fractal);
int key_press(int keycode, t_fractal *fractal);
int key_hook(int keycode, t_fractal *fractal);
int mouse_move_hook(int x, int y, t_fractal *fractal);
int mouse_button_hook(int button, int x, int y, t_fractal *fractal);
#endif