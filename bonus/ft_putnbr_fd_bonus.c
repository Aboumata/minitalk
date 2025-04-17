/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:30:05 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/17 17:30:07 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

void	ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return ;
    write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
    if (fd < 0)
        return ;
    if (s == NULL)
        return ;
    write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
    if (fd < 0)
        return ;
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd(n % 10 + '0', fd);
}
