/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:34:46 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/11/15 13:34:35 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

# include <libc.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*line(int fd, char *str);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s);
char	*ft_strdup(char *s1);
char	*ft_strdu(char *s1);

# endif
