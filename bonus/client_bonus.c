/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:33:40 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/17 09:33:41 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sig)
{
    (void)sig;
    g_ack_received = 1;
}

void	send_bit(int pid, char bit)
{
    sigset_t	mask;
    sigset_t	old_mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, &old_mask);
    g_ack_received = 0;
    if (bit)
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);
    while (!g_ack_received)
        sigsuspend(&old_mask);
    sigprocmask(SIG_SETMASK, &old_mask, NULL);
}

void	send_char(int pid, char c)
{
    int	i;

    i = 8;
    while (i-- > 0)
        send_bit(pid, (c >> i) & 1);
}

void	send_message(int pid, const char *str)
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
    int	valid;

    valid = 1;
    if (argc != 3)
    {
        write(STDOUT_FILENO, "Usage: ./client_bonus [server_pid] [message]\n", 46);
        return (1);
    }
    send_message(ft_atoi(argv[1], &valid), argv[2]);
    return (0);
}
