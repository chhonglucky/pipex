/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:37:37 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/03 16:40:27 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**free_command(char **cmd)
{
	int	iter;

	iter = 0;
	while (cmd[iter])
	{
		free(cmd[iter]);
		iter++;
	}
	free(cmd);
	return (0);
}

char	**parseline(char *cmd, char **command, char **envp)
{
	char	*paths;
	char	**env_paths;

	command = ft_split(cmd, (char) ' ');
	paths = ft_getenv("PATH", envp);
	if (paths == NULL)
		unix_error("PATH cannot be found");
	env_paths = ft_split(paths, (char) ':');
	command[0] = find_cmd(command[0], env_paths);
	free(paths);
	env_paths = free_command(env_paths);
	return (command);
}

char	*find_cmd(char *cmd, char **env_paths)
{
	char	*buf;
	char	*path_cmd;
	int		i;

	if (cmd == 0 || cmd[0] == 0)
		return (0);
	else if (ft_strrchr(cmd, '/') && access(cmd, F_OK) != -1)
		return (cmd);
	else if (ft_strrchr(cmd, '/') && access(cmd, F_OK) == -1)
		return (0);
	buf = ft_strjoin("/", cmd);
	free(cmd);
	i = -1;
	while (env_paths && env_paths[++i])
	{
		path_cmd = ft_strjoin(env_paths[i], buf);
		if (access(path_cmd, F_OK) != -1)
		{
			free(buf);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free(buf);
	return (0);
}

char	*ft_getenv(char *env, char **envp)
{
	int		i;
	char	*paths;

	i = 0;
	paths = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(env, envp[i], ft_strlen(env)) == 0)
		{
			paths = ft_strdup(envp[i] + ft_strlen(env) + 1);
			return (paths);
		}
		i++;
	}
	return (0);
}
