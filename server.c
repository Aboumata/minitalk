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

static t_server_state	g_state;

static void	reset_client_state(pid_t new_pid)
{
	g_state.client_pid = new_pid;
	g_state.current_char = 0;
	g_state.bit_count = 0;
	g_state.index = 0;
}

static void	build_current_char(int sig)
{
	g_state.current_char |= (sig == SIGUSR2) << (7 - g_state.bit_count);
	g_state.bit_count++;
}

static void	process_current_char(void)
{
	if (g_state.current_char == '\0')
	{
		write(STDOUT_FILENO, g_state.buffer, g_state.index);
		write(STDOUT_FILENO, "\n", 1);
		g_state.index = 0;
	}
	else
	{
		if (g_state.index >= BUFFER_SIZE)
		{
			write(STDOUT_FILENO, g_state.buffer, BUFFER_SIZE);
			g_state.index = 0;
		}
		g_state.buffer[g_state.index++] = g_state.current_char;
	}
	g_state.current_char = 0;
	g_state.bit_count = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_state.client_pid != info->si_pid)
		reset_client_state(info->si_pid);
	build_current_char(sig);
	if (g_state.bit_count == 8)
		process_current_char();
	kill(g_state.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	fflush(stdout);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
