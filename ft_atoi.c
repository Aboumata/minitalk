/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:38:38 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/05 11:38:40 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_atoi(const char *str, int *valid)
{
    long	num;
    int	    sign;

    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    sign = 1;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    num = 0;
    while (*str >= '0' && *str <= '9')
    {
        num *= 10;
        num += (*str - '0');
        if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
        {
            *valid = 0;
            return (0);
        }
        str++;
    }
    return (int)(num * sign);
}
