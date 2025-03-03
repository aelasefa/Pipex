/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:54:36 by ayelasef          #+#    #+#             */
/*   Updated: 2025/03/02 03:23:04 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int fd_in, int fd_out)
{
	if (fd_in != -1)
		close(fd_in);
	if (fd_out != -1)
		close(fd_out);
}

void	ft_perror(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

int	check_access(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

char	*valid_cmd(char **split_path, char *cmd)
{
	int		i;
	char	*cmd_path;

	if (!split_path || !cmd)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		cmd_path = ft_strjoin(split_path[i], cmd);
		if (cmd_path && check_access(cmd_path))
			return (free_arr(split_path), cmd_path);
		free(cmd_path);
		i++;
	}
	free_arr(split_path);
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	char	**split_path;
	char	*path;
	char	*valid;

	if (ft_strchr(cmd, '/'))
	{
		if (check_access(cmd))
			return (ft_strdup(cmd));
		return (NULL);
	}
	if (cmd[0] == ' ')
		return (NULL);
	path = get_path(env);
	if (!path)
		return (NULL);
	split_path = ft_split(path, ':');
	if (!split_path)
		return (NULL);
	valid = valid_cmd(split_path, cmd);
	return (valid);
}
