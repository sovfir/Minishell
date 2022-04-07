/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:20:12 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/07 14:30:31 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>

# define BLUE "\033[38;5;36m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define RESETCOLOR "\033[0m"

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

typedef enum e_token_type{
	NONE,
	ARG,
	TRUNC,
	INPUT,
	APPEND,
	PIPE,
	HEREDOC
}			t_token_type;

typedef struct s_token
{
	int				index;
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}				t_token;

//initialization
void	init_env(t_env_v **env_v, char **envp);
void	add_env(t_env_v **env_v, char *name, char *value, bool export);
void	*ft_node();
void	free_spit(char **str);

// utils
char	*ft_strdup(const char *s1);
size_t	ft_strclen(const char *s, char c);
void	ft_lstadd_back(t_env_v **env, t_env_v *new);
char	**ft_split(char	const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_append(char *start, char *end);
void	ft_free_split(char **s);
void	ft_free_tokens(t_token *tokens);
char	*ft_insert(char *start, char *end);
int		ft_isalnum(int c);
bool	ft_isnum(char *s);
char	*ft_itoa(int n);
char	**ft_split_env(const char *s, char c);
char	*ft_replace_word(char *s, char *replace);
char	**ft_split_tokens(t_token *tokens, int type);
int		ft_strchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_write_error(char *command, char *arg, char *error);

#endif