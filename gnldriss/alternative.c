char	*get_next_line(int fd)
{
	static char	*line;
	char		**str;
	
	if (fd < 0 || read (fd, &line, 0) < 0 || BUFFER_SIZE <=0)
		return (0);

	str = c_malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
	{
		free(stash);
		return (0);
	}
	line = ft_get(line, stash, fd);
	return (line);
}
