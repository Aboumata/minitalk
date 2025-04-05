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

#define BUFFER_SIZE 1024

typedef struct {
	char    buffer[BUFFER_SIZE];
	int     index;
	pid_t   client_pid;
	char    current_char;
	int     bit_count;
} t_server_state;

static t_server_state state = {.buffer = {0}, .index = 0, .client_pid = 0, .current_char = 0, .bit_count = 0};

void handle_signal(int sig, siginfo_t *info, void *context) {
	(void)context;

	if (state.client_pid != info->si_pid) {
		state.client_pid = info->si_pid;
		state.current_char = 0;
		state.bit_count = 0;
		state.index = 0;
	}

	state.current_char |= (sig == SIGUSR2) << (7 - state.bit_count);
	state.bit_count++;

	if (state.bit_count == 8) {
		if (state.current_char == '\0') {
			write(STDOUT_FILENO, state.buffer, state.index);
			write(STDOUT_FILENO, "\n", 1);
			state.index = 0;
		} else {
			// Flush buffer if full
			if (state.index >= BUFFER_SIZE) {
				write(STDOUT_FILENO, state.buffer, BUFFER_SIZE);
				state.index = 0;
			}
			state.buffer[state.index++] = state.current_char;
		}
		state.current_char = 0;
		state.bit_count = 0;
	}

	kill(state.client_pid, SIGUSR1);
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
}
