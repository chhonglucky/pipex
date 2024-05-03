/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:41:24 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/03 16:46:50 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <sys/wait.h>
# include "ft_printf/includes/ft_printf.h"
# include "csfunc.h"
# include "ft_printf/Libft/libft.h"

void	process(char **argv, char **envp);
char	**free_command(char **cmd);
void	child1_process(char **command, char *infile, int output_fd[2],
			char **envp);
void	child2_process(char **command, int input_fd[2], char *outfile,
			char **envp);
char	**parseline(char *buf, char **argv, char **envp);
char	*find_cmd(char *cmd, char **envp);
char	*ft_getenv(char *env, char **envp);

#endif