/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:02:03 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/26 12:13:17 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_arg(int ac, char **av)
{
	int	total_args;

	(void)av;
	total_args = 5;
	while (ac < total_args)
	{
		ft_printf("Invalid number of arguments\n");
		exit(3);
	}
	return (2);
}

void	check_env(int ac, char **av, char **env, int i)
{
	if (*env != NULL)
		return ;
	while (i < ac - 1)
	{
		ft_printf("Command not found: %s\n", av[i]);
		i++;
	}
	exit(2);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;

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
