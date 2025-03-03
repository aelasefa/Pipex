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

#include "pipex_bonus.h"

void	check_emty_cmd(int ac, char **av)
{
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		if (!av[i][0] || av[i][0] == ' ')
		{
			ft_putstr_fd("permission denied:\n", 2);
		}
		i++;
	}
}

int	check_arg(int ac, char **av)
{
	int	expected_args;
	int	is_here_doc;

	check_emty_cmd(ac, av);
	if (ac < 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(3);
	}
	is_here_doc = 0;
	if (ft_strcmp("here_doc", av[1]) == 0)
		is_here_doc = 1;
	expected_args = 5;
	if (is_here_doc)
		expected_args = 6;
	if (ac < expected_args)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(3);
	}
	if (is_here_doc)
		return (3);
	return (2);
}

void	check_env(int ac, char **av, char **env, int i)
{
	if (*env != NULL || env != NULL)
		return ;
	while (i < ac - 1)
	{
		if (!find_path(av[i], env))
		{
			ft_putstr_fd("Command not found:", 2);
			ft_putstr_fd(av[i], 2);
			write(2, "\n", 1);
		}
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
