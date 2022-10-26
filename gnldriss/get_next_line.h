/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:34 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/26 21:10:22 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
char	*get_next_line(int fd);
char	*ft_get(char * line, char **stash, int fd);
int	ft_isnewline(char *s);
char	*ft_strjoin(char *dst, char *src);
void	*c_malloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_clean(char *stash, int i);
#endif