/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:57:31 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/18 18:21:00 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

static char	*ft_strdup(char *str)
{
	int		i;
	char	*copied_str;

	i = 0;
	if (!str)
		return (NULL);
	copied_str = malloc(sizeof(*copied_str) * ft_strlen(str) + 1);
	if (!copied_str)
		return (NULL);
	while (str[i])
	{
		copied_str[i] = str[i];
		i++;
	}
	copied_str[i] = '\0';
	return (copied_str);
}

static size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	j = ft_strlen(dst);
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (dstsize < 1 || dstsize < size_dst)
		return (size_src + dstsize);
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (size_dst + size_src);
}

static size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat_str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	cat_str = malloc(sizeof(*cat_str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat_str)
		return (NULL);
	ft_strlcpy(cat_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(cat_str, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	free(s1);
	return (cat_str);
}
