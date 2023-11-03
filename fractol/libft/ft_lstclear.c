/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 07:54:30 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/11 11:58:59 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		clear = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = clear;
	}
	lst = NULL;
}
