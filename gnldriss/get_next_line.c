/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:37 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/26 17:05:47 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char *tst;
	static char	*stash;
	
	if (fd < 0 || read (fd, &line, 0) < 0 || BUFFER_SIZE <=0)
		return (0);
	stash = c_malloc(1 * sizeof(char));
	line = c_malloc(BUFFER_SIZE + 1);
	if (!line)
	{
		free(stash);
		return (0);
	}
	tst = ft_get(line, stash, fd);
	return (tst);
}

char	*ft_get(char * line, char *stash, int fd)
{
	int	i;
	char	*line_r;
	
	while (read(fd, line, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, line);
		if (ft_isnewline(stash) >= 0)
		{
			line_r = c_malloc(ft_isnewline(stash) + 2);
			i = ft_isnewline(stash);
			while(i >= 0)
			{
				line_r[i] = stash[i];
				i--;
			}
			// free(line);
			return (line_r);
		}
	}
	return (0);
}

size_t	ft_isnewline(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 10)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*rst;
	int		i;

	i = 0;
	rst = c_malloc(ft_strlen(dst)+ ft_strlen(src) + 1);
	if (!rst)
		return (0);
	while (dst[i])
	{
		rst[i] = dst[i];
		i++;
	}
	while (*src)
	{
		rst[i++] = *src;
		src++;
	}
	free(dst);
	return (rst);
}