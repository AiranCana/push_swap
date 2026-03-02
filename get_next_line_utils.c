/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:07:44 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/28 12:56:32 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *str, int leter)
{
	char	*s;

	if (!str)
		return (NULL);
	s = (char *) str;
	while (*s && *s != leter)
		s++;
	if (*s == leter)
		return (s);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr_gnl(char *s, size_t len)
{
	char	*line;
	size_t	post;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen_gnl(s);
	if (len > slen)
		len = slen;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	post = 0;
	while (post < len)
	{
		line[post] = s[post];
		post++;
	}
	line[post] = '\0';
	return (line);
}

char	*ft_strjoin_gnl(char const *str1, char const *str2)
{
	size_t		lon;
	char		*str;
	long long	count;
	int			aux;

	count = -1;
	if (!str1 && !str2)
		return (NULL);
	if (!str2)
		return (ft_substr_gnl((char *)str1, ft_strlen_gnl(str1)));
	if (!str1)
		return (ft_substr_gnl((char *)str2, ft_strlen_gnl(str2)));
	lon = ft_strlen_gnl(str1) + ft_strlen_gnl(str2);
	str = malloc(sizeof (char) * (lon + 1));
	if (!str || (!str1 && !str2))
		return (NULL);
	while (++count > -1 && str1[count])
		str[count] = str1[count];
	aux = count;
	count = -1;
	while (++count > -1 && str2[count])
		str[count + aux] = str2[count];
	str[lon] = '\0';
	return (str);
}

void	*going_free(char *rfile, char *buf)
{
	if (rfile)
		free(rfile);
	return (buf);
}
