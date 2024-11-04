/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:31:27 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:31:29 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

struct s_stock	*create_node(char	*value)
{
	struct s_stock	*node;
	int				i;

	i = 0;
	node = malloc(sizeof(struct s_stock));
	while (value[i])
	{
		node->value[i] = value[i];
		i++;
	}
	node->value[i] = '\0';
	node->next = NULL;
	return (node);
}

void	add_back(char	*value, struct s_stock **head)
{
	struct s_stock	*new_node;
	struct s_stock	*current;

	new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	check_if_endline(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static struct s_stock	*stock;
	int						read_r;
	char					buffer[BUFFER_SIZE];
	char					*res;

	buffer[0] = '\0';
	while (!check_if_endline(buffer))
	{
		read_r = read(fd, buffer, BUFFER_SIZE);
		if (read_r <= 0)
			break ;
		if (read_r < BUFFER_SIZE)
			buffer[read_r] = '\0';
		add_back(buffer, &stock);
	}
	res = get_line(stock);
	clean_to_endline(&stock);
	if (res[0] == '\0')
		return (NULL);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*te;

// 	fd = open("exemple.txt", O_RDONLY);
// 	te = get_next_line(fd);
// 	while (te != NULL)
// 	{
// 		printf("%s", te);
// 		te = get_next_line(fd);
// 	}
// 	return (0);
// }
