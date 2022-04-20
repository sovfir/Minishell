/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:22:12 by lshonta           #+#    #+#             */
/*   Updated: 2022/04/20 14:39:14 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token *init_token(void)
{
	t_token *new_token;
	
	new_token = malloc(sizeof(t_token));
	new_token->index = 0;
	new_token->value = NULL;
	new_token->next = NULL;
	new_token->type = NONE;
	return (new_token);
}

void	input_data(t_token *token, char **line, int i)
{
	if (ft_strcmp(line[i], "|"))
	{
		token->type = PIPE;
		token->value = ft_strdup(line[i]);
	}
	else if (ft_strcmp(line[i], "<"))
	{
		token->type = INPUT;
		token->value = ft_strdup(line[i]);
	}
	else if (ft_strcmp(line[i], ">"))
	{
		token->type = TRUNC;
		token->value = ft_strdup(line[i]);	
	}
	else if (ft_strcmp(line[i], ">>"))
	{
		token->type = APPEND;
		token->value = ft_strdup(line[i]);
	}
	else if (ft_strcmp(line[i], "<<"))
	{
		token->type = HEREDOC;
		token->value = ft_strdup(line[i]);
	}
}

static void get_token(t_token *token, char **line)
{
	t_token	*new_token;
	int		i;
	
	i = 0;
	while(line[i] != NULL)
	{
		token->index = i;
		input_data(token, line, i);
		if (token->type == NONE)
			token->value = ft_strdup(line[i]);
		if (line[i + 1] != NULL)
		{
			new_token = init_token();
			token->next = new_token;
			token = token->next;
		}
		i++;
	}
}

t_token *ft_lexer(char **line)
{
	t_token *token;
	
	if (line == NULL)
		return (NULL);
	token = NULL;
	token = init_token();
	get_token(token, line);
	ft_free_split(line);
	return (token);
}