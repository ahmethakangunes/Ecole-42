/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:18:14 by agunes            #+#    #+#             */
/*   Updated: 2022/03/03 12:30:30 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_checker(pid_t pid, int sign)
{
	if (kill(pid, sign) == -1)
		ft_printf("Mesaj gösterme sırasında hata ile karşılaşıldı.");
}

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server Process ID: %d\n", pid);
}

void	take_bit(int sig, siginfo_t *info, void *cnt)
{
	static int	g_number;
	static int	g_bit_count;

	(void) cnt;
	g_number <<= 1;
	if (sig == SIGUSR1)
			g_number = g_number | 1;
	g_bit_count++;
	if (g_bit_count == 8)
	{
		write(1, &g_number, 1);
		if (g_number == 0)
		{
			ft_printf("\nMesaj %d PID numarasından geldi.\n", info->si_pid);
			kill_checker(info->si_pid, SIGUSR1);
		}
		g_number = 0;
		g_bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	test;

	(void)argv;
	(void)argc;
	test.sa_sigaction = take_bit;
	if ((sigaction(SIGUSR1, &test, NULL)) == -1)
		ft_printf("SIGACTION ERROR");
	if ((sigaction(SIGUSR2, &test, NULL)) == -1)
		ft_printf("SIGACTION ERROR");
	print_pid();
	while (1)
		continue ;
}
