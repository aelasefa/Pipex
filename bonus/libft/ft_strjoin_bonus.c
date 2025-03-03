/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:18:34 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/26 12:12:57 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*ft_strdup(char *s1)
{
	char	*dst_d;
	size_t	size;
	int		i;

	size = ft_strlen(s1);
	dst_d = malloc(sizeof(char) * size + 1);
	if (!dst_d)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst_d[i] = s1[i];
		i++;
	}
	dst_d[i] = '\0';
	return (dst_d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *(arr);
	int (i), (j);
	arr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!arr)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '/';
	i++;
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	return (arr);
}
