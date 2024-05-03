/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:04:01 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/03 16:41:11 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "csfunc.h"

void	unix_error(char *msg)
{
	extern int	errno;

	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
}

pid_t	shell_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		unix_error("Fork error");
	return (pid);
}

void	shell_execve(const char *filename, char *argv[], char *const envp[])
{
	printf("%s\n", filename);
	if (execve(filename, argv, envp) < 0)
		unix_error("Execve error");
}

pid_t	shell_waitpid(pid_t pid, int *iptr, int options)
{
	pid_t	retpid;

	retpid = waitpid(pid, iptr, options);
	if (retpid < 0)
		unix_error("Waitpid error");
	return (retpid);
}

int	shell_dup2(int fd1, int fd2)
{
	int	rc;

	rc = dup2(fd1, fd2);
	if (rc < 0)
		unix_error("Dup2 error");
	return (rc);
}
