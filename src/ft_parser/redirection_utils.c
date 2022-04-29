/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:48:41 by lshonta           #+#    #+#             */
/*   Updated: 2022/04/29 20:03:57 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int **create_array(t_token *tokens)
{
    int **arr;
    int i;
    bool    no_error;

    arr =  ft_calloc(2, sizeof(int  *));
    if (arr == NULL)
        return (NULL);
    i = count_redirections(tokens, INPUT, HEREDOC);
    arr[0] = ft_calloc(i + 1, sizeof(int));
    i = count_redirections(tokens, TRUNC, APPEND);
    arr[1] = ft_calloc(i + 1, sizeof(int));
    if (arr[0] == NULL || arr[1] == NULL)
        return (NULL);
    no_error = safe_redirections(tokens, INPUT, HEREDOC, arr[0]);
    if (no_error == true)
		no_error = safe_redirections(tokens, TRUNC, APPEND, arr[1]);
	if (no_error == false)
	{
		free(arr[0]);
		free(arr[1]);
		free(arr);
		return (NULL);
	}
	return (arr);
}