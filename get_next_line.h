/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:09 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:32:10 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

struct s_stock
{
	char			value[BUFFER_SIZE];
	struct s_stock	*next;
};

char	*get_next_line(int fd);
char	*get_line(struct s_stock *head);
void	clean_to_endline(struct s_stock **head);
int		check_if_endline(char *str);
void	add_back(char *value, struct s_stock **head);

#endif
