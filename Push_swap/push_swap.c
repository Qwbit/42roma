/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 05:12:38 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/12/04 23:53:59 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

typedef struct node
{
	int digit;
	int index;
	int size;

	struct node *next;
	struct node *prev;
} node;

void ft_size(node **head, char **s)
{

	int i;
	int j;
	node *last;

	last = *head;
	i = 0;
	j = 0;
	while (s[i])
	{
		ft_split(*s, ' ');
		i++;
	}
	j = i + 1;
	i = 0;
	while (i <= j)
	{
		last->size = j;
		last = last->next;
		i++;
	}
}

// Stack
void ft_new_node(node **head, int value, int index)
{
	node *newNode = malloc(sizeof(node));
	node *last = *head;

	newNode->index = index;
	newNode->digit = value;
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}
	newNode->prev = last;
	last->next = newNode;
}

void ft_close_circle(node **head)
{
	if (*head == NULL)
		return;
	node *last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *head;
	(*head)->prev = last;
}

void ft_make_list(node **head, char **av, int flag)
{

	char **s;
	int i;

	i = 0;
	s = ft_split(av[1], ' ');

	while (s[i])
	{
		if (flag == 1)
			ft_new_node(head, ft_atoi(s[i]), i);
		if (flag == 0)
			ft_new_node(head, 0, i);
		i++;
	}
	ft_size(head, av);
	ft_close_circle(head);
}

// Function

void ra(node **head)
{
	node *current;
	int i;

	i = 0;
	current = *head;
	while(current->index != 0)
	{
	current = current->next;
	i++;
	}
	current = current->next;
	i = 0;

	while (i <= current->size)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void rb(node **head)
{
	node *current;
	int i;

	i = 0;
	current = *head;
	while(current->index != 0)
	{
	current = current->next;
	i++;
	}
	current = current->next;
	i = 0;

	while (i <= current->size)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}



void rra(node **head)
{
	node *current;
	int i;

	current = *head;
	i = 0;
	while(current->index != 0)
		current = current->next;
	
		current = current->prev;
	i = 0;
	while (i <= current->size)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void rrb(node **head)
{
	node *current;
	int i;

	current = *head;
	i = 0;
	while(current->index != 0)
		current = current->next;
	
		current = current->prev;
	i = 0;
	while (i <= current->size)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void rr(node **a, node **b)
{
	ra(a);
	rb(b);
}

void rrr(node **a, node **b)
{
rra(a);
rrb(b);
}

void sa(node **head)
{
	node *current;
	int i1;
	int i2;
	current = *head;

		while(current->index != 0)
	{
		current = current->next;
	}
	i1 = current->digit;
	i2 = current->next->digit;
	current->digit = i2;
	current->next->digit = i1;
}

void sb(node **head)
{
	node *current;
	int i1;
	int i2;
	current = *head;

		while(current->index != 0)
	{
		current = current->next;
	}
	i1 = current->digit;
	i2 = current->next->digit;
	current->digit = i2;
	current->next->digit = i1;
}

void ss(node **a, node **b)
{
sa(a);
sa(b);
}

void pa(node **a, node **b)
{
node *current_a;
node *current_b;
int digit_a;
int digit_b;

current_a = *a;
current_b = *b;
	while(current_a->index != 0)
		current_a = current_a->next;
	while(current_b->index != 0)
		current_b = current_b->next;
	digit_a = current_a->digit;
	digit_b = current_b->digit;
	if(current_a->digit == 0)
		return;
	if(current_a->digit != 0)
	{
		current_a->digit = digit_b;
		current_b->digit = digit_a;
	}
}

void ft_print(node **a, node **b)
{

	node *cura;
	node *curb;
	int j = 0;
	cura = *a;
	curb = *b;

	while(cura->index != 0)
		cura = cura->next;
	while(curb->index != 0)
		curb = curb->next;


	for (int i = 0; i <= (**a).size; i++)
	{
		printf("a:%d i:%d b:%d i:%d \n", cura->digit, cura->index, curb->digit, curb->index);
		cura = cura->next;
		curb = curb->next;
	}
printf("----------------\n");
}

int main(int ac, char **av)
{

	node *a;
	node *b;
	char **s;

	a = NULL;
	b = NULL;

	ft_make_list(&a, av, 1);
	ft_make_list(&b, av, 0);

	s = ft_split(av[1], ' ');
	ft_print(&a,&b);
	sa(&a);
	ft_print(&a,&b);
	pa(&a,&b);
	ft_print(&a,&b);
	ra(&a);
	ft_print(&a,&b);
	rb(&b);
	ft_print(&a,&b);
	rr(&a,&b);
	ft_print(&a,&b);
	rra(&a);
	ft_print(&a,&b);
	rra(&a);
	ft_print(&a,&b);
}