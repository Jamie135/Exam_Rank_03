/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:47:16 by pbureera          #+#    #+#             */
/*   Updated: 2023/02/10 14:51:32 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	*copy;

	str = malloc(10000);
	copy = str;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	while (read(fd, copy, 1) > 0 && *copy++ != '\n');
	return (copy > str) ? (*copy = 0, str) : (free(str), NULL);
}
