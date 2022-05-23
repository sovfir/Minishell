/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:26:24 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:30:40 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*exec_heredoc(char *delimiter)
{
	char	*input;
	char	*tmp;

	input = malloc(1);
	if (input == NULL)
		return (NULL);
	while (1)
	{
		tmp = readline("heredoc> ");
		if (ft_strcmp(tmp, delimiter) == 0)
		{
			if (input != NULL)
				printf("%s", input);
			free(tmp);
			break ;
		}
		if (tmp != NULL && input != NULL)
		{
			tmp = ft_append(tmp, "\n");
			input = ft_append(input, tmp);
			free(tmp);
		}
	}
	return (input);
}
