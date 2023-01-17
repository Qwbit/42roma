/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:45 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/19 16:46:23 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	a_swap;
	int	b_swap;

	a_swap = *a;
	b_swap = *b;
	*a = b_swap;
	*b = a_swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;
	int	array[size];
	int	right_array[size];
	int	selected;

	i = 0;
	j = size;
	selected = 0;
	swap = 1;
	while(i < size)
	{
		array[i] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		while(j > 0 )
		{
			if ((array[j] <  array[j - 1]))
			{
				ft_swap(&array[j],&array[j - 1]);
			}	
			j--;
		}
		j=size;	
		i++;
	}
	j=size;
}
