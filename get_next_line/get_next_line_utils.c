/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:50:11 by agunes            #+#    #+#             */
/*   Updated: 2022/02/08 18:13:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	int		i;
	int		b;
	int		len;
	char	*arr;

	i = 0;
	b = 0;
	len = ft_strlen(left_str) + ft_strlen(buff) + 1;
	arr = (char *)malloc(sizeof(char) * len);
	if (!arr)
		return (0);
	while (left_str && left_str[i] != '\0')
			arr[b++] = left_str[i++];
	i = 0;
	while (buff[i] != '\0')
		arr[b++] = buff[i++];
	free(left_str);
	free(buff);
	arr[b] = '\0';
	return (arr);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	int		b;
	char	*arr;

	i = 0;
	b = 0;
	if (left_str[i] == '\0')
		return (0);
	while (left_str[i] != '\n' && left_str[i] != '\0')
		i++;
	if (left_str[i] == '\n')
			arr = malloc(sizeof(char) * i + 2);
	else
		arr = malloc(sizeof(char) * i + 1);
	if (!arr)
		return (0);
	i = 0;
	while (left_str[i] != '\0' && left_str[i] != '\n')
		arr[b++] = left_str[i++];
	if (left_str[i] == '\n')
		arr[b++] = '\n';
	arr[b] = '\0';
	return (arr);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		b;
	int		len;
	char	*arr;

	i = 0;
	b = 0;
	len = ft_strlen(left_str) + 1;
	while (left_str[i] != '\n' && left_str[i] != '\0')
		i++;
	if (left_str[i] == '\0')
	{
		free(left_str);
		return (0);
	}
	arr = malloc(sizeof(char) * (len - i));
	if (!arr)
		return (0);
	i++;
	while (left_str[i] != '\0')
		arr[b++] = left_str[i++];
	arr[b] = '\0';
	free(left_str);
	return (arr);
}
