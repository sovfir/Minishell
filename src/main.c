/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:13:50 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/08 16:24:21 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handler(int signal)
{
	
	// rl_on_new_line();
	// // rl_replace_line();
	// rl_redisplay();
	if (signal == SIGINT)
	{
		write(1, "  \b\b\n", 5);
		rl_on_new_line();
		rl_newline(0,0);
		rl_redisplay();
	}
	// else
		// write(1, "  \b\b", 4);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*envi;

	if (argc != 1 && argv != NULL)
	{
		perror("ARGUMENT!");
		return (1);
	}
	envi = malloc(sizeof(t_env));
	if (envi == NULL)
		return (1);
	envi->envp = envp;
	init_env(&envi->env_v, envi->envp);
	add_env(&envi->env_v, ft_strdup("?"), ft_strdup("0"), false);
	signal(SIGINT, handler);
	while (1)
	{
		input = readline(BLUE"minishell$ "RESETCOLOR);
		if (input != NULL)
			{
				add_history(input);
				write_history("history.txt");
			}
		// else
		// 	exit(0);
		// ft_parser();
	}
}

// int main()
// {
//         char *inpt;

//         int i = 0;

//         while ( i < 10 )
//         {
//                 inpt = readline("Minishell$ ");
//                 add_history(inpt);
//                 printf("%s", inpt);
//                 printf("\n");
//                 ++i;
//         }

//         return 0;

// }