/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:48:38 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/18 16:36:28 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_bzero(void *str, size_t len)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) str;
	i = 0;
	while (len > 0)
	{
		ptr[i] = 0;
		i++;
		len --;
	}
	return (str);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_handle_pre_endl(char *str, size_t len)
{
	int		i;
	char	*stored;

	i = 0;
	stored = malloc(sizeof(*stored) * (ft_strlen(str) - len + 1));
	if (!stored)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		stored[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		stored[i] = '\n';
		i++;
	}
	stored[i] = '\0';
	return (stored);
}

void	ft_handle_post_endl(char *str, char*buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
		buff[j] = str[i];
		j++;
		i++;
	}
	buff[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*remainder;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	i = BUFFER_SIZE;
	remainder = ft_strjoin(NULL, buffer[fd]);
	while (i == BUFFER_SIZE && ft_strchr(buffer[fd], '\n') == 0)
	{
		ft_bzero(buffer[fd], BUFFER_SIZE + 1);
		i = read(fd, buffer[fd], BUFFER_SIZE);
		remainder = ft_strjoin(remainder, buffer[fd]);
	}
	ft_handle_post_endl(remainder, buffer[fd]);
	if (!remainder[0] && i != BUFFER_SIZE)
		line = NULL;
	else
		line = ft_handle_pre_endl(remainder, ft_strlen(buffer[fd]));
	free(remainder);
	return (line);
}
