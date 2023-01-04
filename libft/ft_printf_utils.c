/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:52:54 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/04 18:28:11 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	if (str == NULL)
		*len += write(1, "(null)", 6);
	else
		*len += write(1, str, ft_strlen_2(str));
}

void	ft_putnbr(int n, int *len)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-', len);
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr(i / 10, len);
	ft_putchar(i % 10 + '0', len);
}

void	ft_putuns(unsigned int i, int *len)
{
	if (i > 9)
		ft_putuns(i / 10, len);
	ft_putchar(i % 10 + '0', len);
}
