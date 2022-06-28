/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:18:08 by agunes            #+#    #+#             */
/*   Updated: 2022/03/03 12:31:19 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_checker(pid_t pid, int sign)
{
	if (kill(pid, sign) == -1)
	{
		ft_printf("Mesajınız iletilemedi(process ID veya sinyal hatalı).");
		exit(1);
	}
}

void	send_bits(unsigned char c, pid_t pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if ((c >> count) & 1)
			kill_checker(pid, SIGUSR1);
		else
			kill_checker(pid, SIGUSR2);
		count--;
		usleep(50);
	}
}

void	sended(int signo)
{
	(void)signo;
	ft_printf("Mesajınız başarıyla iletildi.");
}

int	main(int argc, char **argv)
{
	pid_t	serverpid;
	int		i;
	int		b;

	if (argc < 3)
		return (1);
	i = 2;
	serverpid = ft_atoi(argv[1]);
	signal(SIGUSR1, sended);
	while (argv[i])
	{
		b = 0;
		while (argv[i][b])
			send_bits(argv[i][b++], serverpid);
		send_bits(' ', serverpid);
		i++;
	}
	send_bits('\0', serverpid);
	return (0);
}
