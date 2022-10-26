/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:34 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/26 16:38:20 by apple            ###   ########.fr       */
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
char	*ft_get(char * line, char *stash, int fd);
size_t	ft_isnewline(char *s);
char	*ft_strjoin(char *dst, char *src);
char	*c_malloc(size_t n);
size_t	ft_strlen(const char *s);
#endif