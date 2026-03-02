/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:11:18 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/28 12:27:16 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# ifndef BREAKER
#  define BREAKER '\n'
# endif

size_t	ft_strlen_gnl(const char *s);

char	*ft_strjoin_gnl(char const *str1, char const *str2);
char	*ft_strchr_gnl(const char *str, int leter);
char	*ft_substr_gnl(char *s, size_t len);
char	*get_next_line(int fd);

void	*going_free(char *rfile, char *buf);

#endif
