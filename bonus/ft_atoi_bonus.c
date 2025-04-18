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

#include "minitalk_bonus.h"

int	ft_atoi(const char *str, int *valid)
{
	long	result;

	int (sign), i;
	result = 0;
	sign = 1;
	i = 0;
	*valid = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] == '\0')
		return (*valid = 0, 0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (*valid = 0, 0);
		result = result * 10 + (str[i++] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (*valid = 0, 0);
	}
	return ((int)(result * sign));
}
