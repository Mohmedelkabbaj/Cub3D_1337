/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:26:04 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/23 17:22:38 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>


int		ft_isalpha(int alpha);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int num);
int		ft_isspace(char c);
int		ft_isprint(int c);
int		ft_tolower(int j);
int		ft_toupper(int j);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *k, int c, size_t len);
char	*ft_strchr(char *str, int j);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(char *s, int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char sep);
char	*ft_itoa(int l);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
