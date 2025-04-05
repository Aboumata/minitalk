/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:08:47 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/05 10:08:51 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(const int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_bit(const int pid, const char bit)
{
	sigset_t mask, old_mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigprocmask(SIG_BLOCK, &mask, &old_mask);
	g_ack_received = 0;
	kill(pid, bit ? SIGUSR2 : SIGUSR1);
	while (!g_ack_received)
		sigsuspend(&old_mask);
	sigprocmask(SIG_SETMASK, &old_mask, NULL);
}

void	send_char(const int pid, const char c)
{
	int	i;

	i = 8;
	while (i--)
		send_bit(pid, (c >> i) & 1);
}

void	send_message(const int pid, const char *str)
{
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Usage: ./client [server_pid] [message]\n", 38);
		return (1);
	}
	send_message(atoi(argv[1]), argv[2]);
	return (0);
}
