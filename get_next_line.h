/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:22:45 by bmetehri          #+#    #+#             */
/*   Updated: 2023/04/27 03:23:20 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	read_and_stack(int fd ,t_list **mylist);
int		new_line_founded(t_list *mylist);
t_list	*ft_lst_get_last(t_list *mylist);
void	add_to_mylist(t_list **mylist, char *buffer, int readed_chars);
void	get_line(t_list *mylist, char **line);
void	allocate_memory_to_line(char **line, t_list *mylist);
void	clean_list(t_list **mylist);
int		ft_strlen(char *str);
void	free_list(t_list *mylist);

#endif
