/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:19 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/04 15:31:53 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_arg = ft_split(argv[2], ' ');
	pipex.cmd = find_cmd(pipex.cmd_arg[0], pipex.cmd_paths);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		p_err(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_arg = ft_split(argv[3], ' ');
	pipex.cmd = find_cmd(pipex.cmd_arg[0], pipex.cmd_paths);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		p_err(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (p_err(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		mess_err(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		mess_err(ERR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		mess_err(ERR_PIPE);
	pipex.paths = cmd_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	closing(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
