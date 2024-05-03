/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:12:22 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/03 17:27:40 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("input format : ./pipex file1 cmd1 cmd2 file2\n",
			STDERR_FILENO);
		exit(1);
	}
	process(argv, envp);
	return (0);
}

void	process(char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid[2];
	char	**command;

	command = 0;
	shell_pipe(pipe_fd);
	command = parseline(argv[2], command, envp);
	pid[0] = shell_fork();
	if (pid[0] == 0)
		child1_process(command, argv[1], pipe_fd, envp);
	command = free_command(command);
	command = parseline(argv[3], command, envp);
	pid[1] = shell_fork();
	if (pid[1] == 0)
		child2_process(command, pipe_fd, argv[4], envp);
	command = free_command(command);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid[0], 0, 0);
	waitpid(pid[1], 0, 0);
}

void	child1_process(char **command, char *infile, int output_fd[2],
			char **envp)
{
	int	infile_fd;

	infile_fd = shell_open(infile, O_RDONLY | O_CLOEXEC, 0777);
	shell_dup2(infile_fd, STDIN_FILENO);
	shell_dup2(output_fd[1], STDOUT_FILENO);
	shell_close(output_fd[0]);
	shell_execve(command[0], command, envp);
}

void	child2_process(char **command, int input_fd[2], char *outfile,
			char **envp)
{
	int	outfile_fd;

	outfile_fd = shell_open(outfile, O_CREAT | O_TRUNC | O_WRONLY | O_CLOEXEC,
			0777);
	shell_dup2(input_fd[0], STDIN_FILENO);
	shell_close(input_fd[1]);
	shell_dup2(outfile_fd, STDOUT_FILENO);
	shell_execve(command[0], command, envp);
}
