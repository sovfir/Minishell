/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:03:54 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/20 14:53:22 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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