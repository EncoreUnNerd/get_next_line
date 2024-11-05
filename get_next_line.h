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

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strchr(const char *str, int l);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_to_line(char *readed);
char	*ft_strrchr(const char *str, int l);
char	*get_next_line(int fd);

#endif
