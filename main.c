/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:29 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/26 10:33:23 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

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

void	close_fd(int fd_in, int fd_out)
{
	if (fd_in != -1)
		close(fd_in);
	if (fd_out != -1)
		close(fd_out);
}

int	check_access(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

void	free_arr(char **arr)
{
	int	i;
	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_path(char *cmd, char **env)
{
	char	**split_path;
	char	*cmd_path;
	char	*path;
	int		i;
	if (check_access(cmd))
		return (ft_strdup(cmd));
	path = get_path(env);
	split_path = ft_split(path, ':');
	if (!split_path)
		return (NULL);
	i = 0;
	while (split_path)
	{
		cmd_path = ft_strjoin(split_path[i], cmd);
		if (cmd_path && check_access(cmd_path))
		{
			free_arr(split_path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_arr(split_path);
	return (NULL);
}

void	execute_cmd(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		exit(1);
	path = find_path(split_cmd[0], env);
	if (!path)
	{
		exit(1);
	}
	execve(path, split_cmd, env);
	free(path);
	free_arr(split_cmd);
	exit(1);
}

void	process_pipex(int fd_in, char *cmd, int fd_out, char **env)
{
	pid_t	pid;

	pid = fork();

	if (pid == 0)
	{
	if (dup2(fd_in, 0) == -1)
			exit(1);
	if (dup2(fd_out, 1) == -1)
			exit(1);
		execute_cmd(cmd, env);
		exit(7);
	}
}

void	creat_processs(int ac, char **av, int i, char **env)
{
	int	fd_in;
	int	fd_out;
	int	fd[2];

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		exit(1);
	while (i < ac - 2)
	{
		if (pipe(fd) == -1)
			exit(1);
		process_pipex(fd_in, av[i], fd[1], env);
		close(fd[1]);
		fd_out = fd[0];
		i++;
	}
	fd_out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC | 0777);
	if (fd_out == -1)
		exit(1);
	process_pipex(fd_out, av[i], fd[0], env);
	close_fd(fd_out, fd_in);
	while (wait(NULL) > 0);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	total_args;

	total_args = 5;
	while (ac < total_args)
	{
		ft_printf("Invalid number of arguments\n");
		exit(3);
	}
	return (2);
}

int	main(int ac, char **av, char **env)
{
	char	*path;
	char	**split_path;
	int	fd[2];
	int i;

	i = check_arg(ac, av);
	if (ac != 5)
	{
		ft_printf("Error: Bad arguments\n");
		ft_printf("./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		return (1);
	}
	if (pipe(fd) == -1)
			exit(1);
	creat_processs(ac, av, i, env);
}
