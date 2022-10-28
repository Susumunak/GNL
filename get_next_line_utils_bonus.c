/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:40 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/28 21:07:37 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*c_malloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	p = (void *) malloc(nmemb * size);
	if (!p)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*rst;
	int		i;

	i = 0;
	if (!dst)
	{
		dst = c_malloc(1, sizeof(char));
		if (!dst)
			return (0);
	}
	rst = c_malloc(ft_strlen(dst) + ft_strlen(src) + 1, sizeof(char));
	if (!rst)
		return (0);
	while (dst && dst[i])
	{
		rst[i] = dst[i];
		i++;
	}
	while (*src)
		rst[i++] = *src++;
	free(dst);
	return (rst);
}

int	is_nl(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
