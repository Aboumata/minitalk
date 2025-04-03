#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// Server
void	handle_signal(int sig, siginfo_t *info, void *context);

// Client
void	send_bit(int pid, char bit);
void	send_char(int pid, char c);
void	send_message(int pid, char *str);

#endif