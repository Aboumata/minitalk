/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:34:00 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/17 18:34:01 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define BUFFER_SIZE 1024

typedef struct s_server_state
{
	char	buffer[BUFFER_SIZE];
	int		index;
	pid_t	client_pid;
	char	current_char;
	int		bit_count;
}			t_server_state;

void		handle_signal(int sig, siginfo_t *info, void *context);
void		send_bit(int pid, char bit);
void		send_char(int pid, char c);
void		send_message(int pid, const char *str);
int			ft_atoi(const char *str, int *valid);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);

#endif // MINITALK_BONUS_H
