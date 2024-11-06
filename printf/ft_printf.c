/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:02:07 by migumar2          #+#    #+#             */
/*   Updated: 2024/01/30 16:46:32 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(char *s, int *total)
{
	if (!s)
		s = "(null)";
	while (*s && *total >= 0)
	{
		if (write (1, s, 1) < 0)
			*total = -1;
		else
			*total += 1;
		s++;
	}
}

void	ft_print_n(long n, char *strbase, int base, int *total)
{
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
		{
			*total = -1;
			return ;
		}
		*total += 1;
		n *= -1;
	}
	if (n >= base)
		ft_print_n(n / base, strbase, base, total);
	if (*total == -1)
		return ;
	if (write (1, &strbase[n % base], 1) < 0)
		*total = -1;
	else
		*total += 1;
}

void	ft_print_p(unsigned long n, int *total)
{
	if (n >= 16)
		ft_print_p(n / 16, total);
	if (*total == -1)
		return ;
	if (write (1, &"0123456789abcdef"[n % 16], 1) < 0)
		*total = -1;
	else
		*total += 1;
}

void	ft_choose(va_list args, int *total, char c)
{
	if (c == 'c')
		ft_print_c(va_arg(args, int), total);
	if (c == '%')
		ft_print_c('%', total);
	if (c == 's')
		ft_print_s(va_arg(args, char *), total);
	if (c == 'd' || c == 'i')
		ft_print_n((long) va_arg(args, int),
			"0123456789", 10, total);
	if (c == 'u')
		ft_print_n((long) va_arg(args, unsigned int),
			"0123456789", 10, total);
	if (c == 'p')
	{
		ft_print_s("0x", total);
		ft_print_p((unsigned long) va_arg(args, void *), total);
	}
	if (c == 'x')
		ft_print_n((long ) va_arg(args, unsigned int),
			"0123456789abcdef", 16, total);
	if (c == 'X')
		ft_print_n((long ) va_arg(args, unsigned int),
			"0123456789ABCDEF", 16, total);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, str);
	while (str && *str && total >= 0)
	{
		if (*str == '%')
		{
			str++;
			ft_choose(args, &total, *str);
		}
		else
		{
			if (write(1, str, 1) < 0)
				total = -1;
			else
				total += 1;
		}
		str++;
	}
	va_end(args);
	return (total);
}
