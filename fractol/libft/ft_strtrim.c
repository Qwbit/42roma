/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:04:20 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/11 10:39:42 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	franco(const char *str, int c)
{
	while (*str != '\0' && c != *str)
		str++;
	if (c == *str)
		return (c);
	return ('\0');
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		string_size;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] == franco(set, s1[start]) && start <= end)
		start++;
	while (s1[end] == franco(set, s1[end]) && end != 0)
	{
		end--;
	}
	if (start == ft_strlen(s1) && end == 0)
		return (ft_strdup(""));
	string_size = end - start + 1;
	return (ft_substr(s1, start, string_size));
}

// int main()
// {
// 	char *str;

// 	str = ft_strtrim("   xxx   xxx", " x");
// 	if (!str)
// 	{
// 		printf("(NULL)\n");
// 		return (0);
// 	}
// 	printf("%s \n",str);
// 	free(str);

// }