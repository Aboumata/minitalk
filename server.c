/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:08:57 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/05 10:08:59 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bit_count = 0;
static char	g_current_char = 0;

void	handle_signal(int sig)
{
	g_current_char |= (sig == SIGUSR2) << (7 - g_bit_count);
	g_bit_count++;
	if (g_bit_count == 8)
	{
		write(STDOUT_FILENO, &g_current_char, 1);
		if (g_current_char == '\0')
			write(STDOUT_FILENO, "\n", 1);
		g_bit_count = 0;
		g_current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(STDOUT_FILENO, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
