/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:23:06 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:31:30 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handler(int signal)
{
	rl_on_new_line();
	rl_redisplay();
	if (signal == SIGINT)
	{
		write(1, "  \b\b\n", 5);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		write(1, "  \b\b", 4);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_env	*env;

	if (argc != 1 && argv != NULL)
	{
		perror(RED"Usage: ./minishell");
		return (1);
	}
	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (1);
	env->envp = envp;
	init_env(&env->env_v, env->envp);
	add_env(&env->env_v, ft_strdup("?"), ft_strdup("0"), false);
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	while (true)
	{
		line = readline(GREEN"minishell$ "RESETCOLOR);
		if (line != NULL)
			add_history(line);
		else
			ft_exit(NULL, true, env->env_v);
		parser(line, env);
	}
}
