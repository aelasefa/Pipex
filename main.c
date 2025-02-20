/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:29 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/20 10:40:36 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{

	int	i;
	char *path;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			path = env[i];
		i++;
	}
	return (path + 5);
}

int	main(int ac, char **av, char **env)
{
	char	*path;
	char	**split_path;

	path = get_path(env);
	split_path = ft_split(path, ':');
	int i = 0;
	while (split_path[i])
	{
		printf("%s\n",split_path[i]);
		i++;
	}
}
