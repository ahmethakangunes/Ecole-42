/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:28:56 by agunes            #+#    #+#             */
/*   Updated: 2022/05/05 13:29:21 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_checker(pid_t pid, int sign)
{
	if (kill(pid, sign) == -1)
		ft_printf("errorrr :/");
}

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_printf("My Process ID: %d\n", pid);
}

void	take_bit(int sig, siginfo_t *info, void *cnt)
{
	static int	g_number;
	static int	g_bit_count;

	(void) cnt;
	g_number <<= 1;
	if (sig == SIGUSR1)
			g_number |= 1;
	g_bit_count++;
	if (g_bit_count == 8)
	{
		ft_printf("%c", g_number);
		if (g_number == 0)
		{
			ft_printf("\nMessage came from this process id: %d\n", info->si_pid);
			kill_checker(info->si_pid, SIGUSR1);
		}
		g_number = 0;
		g_bit_count = 0;
	}
}

void	ctrlc(int sig)
{
	(void)sig;
	ft_printf("\n Stopped by CTRL + C :D\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	struct sigaction	test;

	(void)argv;
	(void)argc;
	test.sa_sigaction = take_bit;
	if ((sigaction(SIGUSR1, &test, NULL)) == -1)
		ft_printf("sigaction error");
	if ((sigaction(SIGUSR2, &test, NULL)) == -1)
		ft_printf("sigaction error");
	signal(SIGINT, ctrlc);
	print_pid();
	while (1)
		continue ;
}

/*

int g_number = 0;
int g_bit_count = 0;

void    print_pid()
{
	int pid = getpid();
	printf("Benim Process ID'm: %d\n", pid);
}

void take_zero(int sig)
{
	g_number <<= 1;
	g_bit_count++;
   // write(1, "0", 1);
  // printf("zero: %d", g_number);
}

void take_one(int sig)
{  
	g_number <<= 1;
   g_number ^=1;
 
   g_bit_count++;
   // write(1, "1", 1);
	//printf("mesaj %s");
}

int main(int argc, char **argv)
{
	print_pid();
	signal(SIGUSR1, take_one);
	signal(SIGUSR2, take_zero);
	while(1)
	{
		if (g_bit_count == 8)
		{ 
			printf("Bana gelen veri bu: %c\n", g_number);
			g_number = 0;
			g_bit_count = 0;
		} 
	}  
}*/