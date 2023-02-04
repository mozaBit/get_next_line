/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:19:42 by bmetehri          #+#    #+#             */
/*   Updated: 2023/02/04 09:13:47 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 158

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		check_for_newLine(t_list **lst, size_t line);
t_list	*ft_lstnew(char content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		bam_read(int fd, size_t count, t_list **lst);
int		ft_lstclear(t_list **lst);
char	*get_stuff(size_t line, t_list **lst, int backs);

#endif
