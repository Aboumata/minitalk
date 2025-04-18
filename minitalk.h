/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:58:47 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/05 10:58:49 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct s_server_state
{
	char	buffer[BUFFER_SIZE];
	int		index;
	pid_t	client_pid;
	char	current_char;
	int		bit_count;
}			t_server_state;

void		handle_signal(int sig);
void		send_bit(int pid, char bit);
void		send_char(int pid, char c);
void		send_message(int pid, const char *str);
int			ft_atoi(const char *str, int *valid);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

#endif