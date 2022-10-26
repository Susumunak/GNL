/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:37 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/26 21:11:03 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	
	if (fd < 0 || read (fd, &line, 0) < 0 || BUFFER_SIZE <=0)
		return (0);
	// if (stash == NULL)
	// {
	// 	stash = c_malloc(2);
	// }
	line = c_malloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
	{
		free(stash);
		return (0);
	}
	line = ft_get(line, &stash, fd);
	return (line);
}

char	*ft_get(char * line, char **stash, int fd)
{
	int	i;
	char	*line_r;
	
	while (read(fd, line, BUFFER_SIZE) > 0)
	{
		*stash = ft_strjoin(*stash, line);
		// printf ("joining :[%s]\n",*stash);
		if (ft_isnewline(*stash) >= 0)
		{
			line_r = c_malloc(ft_isnewline(*stash) + 2, sizeof(char));
			i = ft_isnewline(*stash);
			while(i >= 0)
			{
				line_r[i] = (*stash)[i];
				i--;
			}
			free (line);
			// printf ("return value :[%s]\n",line_r);
			
			*stash = ft_clean(*stash, ft_isnewline(*stash) + 1);
			return (line_r);
		}
	}
	return (0);
}

char	*ft_clean(char *stash, int i)
{
	char	*new_stash;
	int j;
	
	j = 0;
	new_stash = c_malloc(ft_strlen(&stash[i]) + 1, sizeof(char));
	while(stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	free(stash);
	return(new_stash);
}

int	ft_isnewline(char *s)
{
	int	i;

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
	int	j;

	i = 0;
	j = 0;
	rst = c_malloc(ft_strlen(dst)+ ft_strlen(src) + 1, sizeof(char));
	if (!rst)
		return (0);
	while (dst && dst[i])
	{
		rst[i] = dst[i];
		i++;
	}
	while (src[j])
	{
		rst[i] = src[j];
		j++;
		i++;
	}
	free(dst);
	return (rst);
}