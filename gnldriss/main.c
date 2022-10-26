/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:46:18 by del-khay          #+#    #+#             */
/*   Updated: 2022/10/26 17:04:44 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("./driss.txt", O_RDWR);
	// write (fd,"hello pussy\n", 12);
	char *s = get_next_line(fd);
	printf("%s", s);
}
