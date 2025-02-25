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

	if (!env || !(*env))
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			path = env[i];
			return (path + 5);
		}
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	char	*path;
	char	**split_path;
	int i, j;
	/*t_pipe *cmnd;*/
	/*if (ac  < 5)*/
	/*{*/
	/*	ft_printf("Error: Invalid number of arguments.\n./pipex infile \"ls -l\" \"wc -l\" outfile\n");*/
	/*	exit(1);*/
	/*}*/
	path = get_path(env);
	if (!path)
	{
		perror("Error\n");
		exit(1);
	}
	split_path = ft_split(path, ':');
	char **all_cmnd;
	/*int fd1 = open("infile", O_RDONLY);*/
	i = 1;
	while (i < ac)
	{
		all_cmnd = ft_split(av[i], ' ');
		j = 0;
		while (all_cmnd[j])
		{
			printf("%s ", all_cmnd[j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
