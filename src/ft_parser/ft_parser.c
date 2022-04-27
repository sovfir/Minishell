/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:03:54 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/27 20:02:52 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int get_fd(int *arr)
{
	int i;
	
	i = 0;
	while (arr[i] != -1)
	{
		if (arr[i + 1] == -1)
			return (arr[i]);
		close(arr[i]);
		i++;
	}
	return (-1);
}

static void	remove_heredoc(t_env *env)
{
	char	**tmp;

	if (access("heredoc", F_OK) == 0)
	{
		tmp = ft_calloc(3, sizeof(char *));
		tmp[2] = NULL;
		tmp[0] = ft_strdup("rm");
		tmp[1] = ft_strdup("heredoc");
		execute(tmp, env);
		ft_free_split(tmp);
	}
}

static void	parse_childs(t_token *token, int fd_in, int fd_out, t_env *env)
{
	char	**input;

	dup2(fd_in, STDIN_FILENO);
	if (fd_out != -1)
		dup2(fd_out, STDOUT_FILENO);
	input = convert_token(token); //****
	if(input[0] != NULL)
		execute(input, env); // ****
	ft_free_split(input);
	exit(0);
}

void	parse_redirect(t_env *env, t_token *token)
{
	int	pid;
	int fd_in;
	int	fd_out;
	int	**arr;
	
	arr = creat_arr(token); // ****
	if (arr == NULL)
		return;
	fd_in = get_fd(arr[0]);
	fd_out = get_fd(arr[1]);
	pid = fork();
	if (pid == 0)
		parse_childs(token, fd_in, fd_out, env);
	else
	{
		close(fd_in);
		close(fd_out);
		wait (NULL);
	}
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	remove_heredoc(env);
	
}

void	ft_parser(char *input, t_env *envi)
{
	t_token	*tokens;
	char	**line;

	input = env_vars(input, envi->env_v);
	input = remove_spaces(input);
	tokens = ft_lexer(ft_split(line, ' '));
	if (line[0] != '\0' && check_redict(line && check_quote(line))
	{
		remove_quote(token);
		if (has_pipe(token) == true)
			ft_pipe(token, envi, 0);
		else if (has_redirect(token) == true)
			parse_redirect(env, tokens);
	}
}