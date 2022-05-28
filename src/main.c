/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:23:06 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/28 15:48:15 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	while (true)
	{
		ft_signal(1);
		line = readline(GREEN"minishell$ "RESETCOLOR);
		if (line != NULL)
			add_history(line);
		else
			ft_exit(NULL, true, env->env_v);
		parser(line, env);
	}
}
