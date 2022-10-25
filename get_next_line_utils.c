/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:40 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/25 21:15:44 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*c_malloc(size_t n)
{
	char	*p;

	p = (char *) malloc(n * sizeof(char));
	if (!p)
		return (0);
	while (n >= 0)
		p[n--] = 0;
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
