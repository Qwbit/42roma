/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:45:58 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/28 00:45:59 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
 ** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
 **                              HEADERS
 */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *test, ...);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_num(long long n);
int		ft_print_unsigned(long long n);
int		ft_print_pointer(unsigned long long n);
#endif
