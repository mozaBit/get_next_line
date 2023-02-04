/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:59:32 by bmetehri          #+#    #+#             */
/*   Updated: 2023/02/04 07:29:47 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		byte_read;
	char	*str;

	str = (char *) calloc(160, sizeof(char));
	fd = open("message.txt", O_RDONLY);
	byte_read = read(fd, str, BUFFER_SIZE);
	printf("called read(%d, c, 10). ", fd);
	printf("returned that %d bytes were read.\n", byte_read);
	str[byte_read] = '\0';
	printf("Those bytes are as follows: %s\n", str);
	return (0);
}
