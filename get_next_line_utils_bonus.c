/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 05:25:35 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/12 09:01:20 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;
	size_t i;

	if (dst == NULL && src == NULL)
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	while (i + 1 < size && i < srclen)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (srclen);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	int		i;

	i = 0;
	len = sizeof(char) * (unsigned long)ft_strlen(s) + 1;
	dst = (char *)malloc(len);
	if (dst != NULL)
	{
		while (s[i] != '\0')
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
		return (NULL);
	return (dst);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL || s2 == NULL)
		return (s1 == NULL ? ft_strdup(s2) : ft_strdup(s1));
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
