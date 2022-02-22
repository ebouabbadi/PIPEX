/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:45:15 by ebouabba          #+#    #+#             */
/*   Updated: 2022/02/20 19:27:56 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (*(char *)dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*src;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)s1;
	src = (char *)s2;
	string = (char *)malloc(sizeof(char)
			* (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!string)
		return (NULL);
	*string = 0;
	ft_strcat(string, dst);
	ft_strcat(string, src);
	return (string);
}
