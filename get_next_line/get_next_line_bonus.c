/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:35 by agunes            #+#    #+#             */
/*   Updated: 2022/02/08 18:09:45 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	rd_bytes = 1;
	while (!find_nl(left_str) && rd_bytes != 0)
	{	
		buff = malloc(sizeof(char *) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

/* int main(void)
{
	int	fd1;
	int	fd2;
	char *line;
	int i;

	i = 0;
	fd1 = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	while (i <= 5)
	{
		line = get_next_line(fd1);
		printf("fd1 %d= %s\n",i+1, line);
		line = get_next_line(fd2);
		printf("fd2 %d= %s",i+1, line);
		i++;
	}
} */