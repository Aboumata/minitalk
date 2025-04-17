/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:33:50 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/17 09:33:52 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *str, int *valid)
{
    int		res;
    int		sign;

    res = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -1;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    if (*str != '\0')
        *valid = 0;
    return (res * sign);
}

