/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:12:58 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/19 16:40:55 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	i_rev;

	i = 0;
	i_rev = size - 1;
	while (i < size)
	{
		elenco_rev[i_rev] = tab[i];
		i_rev--;
		i++;
	}
}
