/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:31:01 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/23 16:37:08 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}
/*
int		main(void)
{
	char	*s1, *s2;

	s1 = "ciao";
	s2 = "ciaotest";
	//printf("%d\n", ft_strncmp(s1, s2, 1));
    //printf("%d\n", ft_strncmp(s1, s2, 0));
	printf("%d\n", strncmp(s1, s2, 5));
	printf("%d\n", strncmp(s1, s2, 1));
}*/
