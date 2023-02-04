/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:53:13 by bmetehri          #+#    #+#             */
/*   Updated: 2023/02/04 09:53:22 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static size_t	line;
	static size_t	count;
	t_list			**lst;
	char			*returned_str;

	while (!check_for_newLine(lst, line))
	{
		count += 10;
		bam_read(fd, count, lst);
	}
	if (check_for_newLine(lst, line))
	{
		returned_str = get_stuff(line, lst, check_for_newLine(lst, line));
		line++;
		return (returned_str);
	}
	return (NULL);
}

int		check_for_newLine(t_list **lst, size_t line)
{
	// checks if there is a newline added in the lst
	// checks if the new line is not printed yet (while searching for \n it counts them and compare them with line)
	size_t	backs;
	t_list	*list;

	if (!lst)
		return (0);
	list = *lst;
	backs = 1;
	while (list)
	{
		if (list->content =='\n' && backs >= line + 1)
			return (backs);
		else if (list->content =='\n')
			backs += 1;
		list = list->next;
	}
	return (ft_lstclear(lst));
}

int		bam_read(int fd, size_t count, t_list **lst)
{
	// read new content and add them to the lst
	char	*c;
	int		times;

	lst = (t_list **) malloc( count * sizeof(t_list *));
	c = (char *) calloc(count + 1, sizeof(char));
	read(fd, &c, count);
	times = 0;
	while (times < count)
	{
		ft_lstadd_back(lst, ft_lstnew(c[times]));
		times += 1;
	}
	return (0);
}

char	*get_stuff(size_t line, t_list **lst, int backs)
{
	return (NULL);
}
