/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:54:36 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/26 14:03:15 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
