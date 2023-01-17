/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:58:36 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/29 22:23:01 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
write(1, &c, 1);
}

void ft_putstr(char *c)
{

int i = 0;
while (c[i])
{

write(1, &c[i], 1);
i++;

}
}


void ft_putnbr(int nb)
{

int i;


i = 0;


if (nb < 0)
   { ft_putchar('-');
    nb *= -1;}

if (nb >= 10)
{
ft_putnbr(nb / 10 );
ft_putnbr(nb % 10);
}
else
ft_putchar(nb + 48);



}


int main()
{

int i = 0;

while(i != 101)
{

if (i % 3 == 0)
    ft_putstr("fizz");
 else
   ft_putnbr(i);
write(1, "\n", 2);
i++;
}




}