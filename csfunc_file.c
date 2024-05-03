/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:44:16 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/03 16:31:31 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "csfunc.h"

int	shell_open(const char *pathname, int flags, mode_t mode)
{
	int	rc;

	rc = open(pathname, flags, mode);
	if (rc < 0)
		unix_error("Open error");
	return (rc);
}

void	shell_close(int fd)
{
	int	rc;

	rc = close(fd);
	if (rc < 0)
		unix_error("Close error");
}

void	shell_pipe(int fd[2])
{
	int	rc;

	rc = pipe(fd);
	if (rc < 0)
		unix_error("pipe error");
}
