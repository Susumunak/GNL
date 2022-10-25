/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:37 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/25 21:38:44 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	
	if (fd < 0 || read (fd, &line, 0) < 0 || BUFFER_SIZE <=0)
		return (0);
	stash = c_malloc(1 * sizeof(char));
	line = c_malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
	{
		free(stash);
		return (0);
	}
	line = ft_get(line, stash, fd);
	return (line);
}

char	*ft_get(char * line, char *stash, int fd);
{
	while (read(fd, line, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, line);
		if (found new line)
		{
			
		}
	}

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
		rst[i] = *dsrt[i];
		i++;
	}
	while (*src)
		rst[i++] = *src++;
		free(dest);
	return (rst);
}