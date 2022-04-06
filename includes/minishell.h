/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:20:12 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/06 16:20:50 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <limits.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>


typedef struct s_env
{
	char	**envp;
	struct s_env_v *env_v;
	
}	t_env;

typedef struct s_env_v
{
	char	*name;
	char	*value;
	bool	export;
	struct s_env_v	*next;
} t_env_v;

void	init_env(t_env_v **env_v, char **envp);
void	*ft_node();
void	free_spit(char **str);
void	add_env(t_env_v **env_v, char *name, char *value, bool export);

#endif