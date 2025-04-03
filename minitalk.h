#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	handle_signal(int sig, const siginfo_t *info, const void *context);
void	send_bit(int pid, char bit);
void	send_char(int pid, char c);
void	send_message(int pid, const char *str);

#endif