/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:03:54 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/20 14:19:44 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_parser(char *input, t_env *envi)
{
	t_token	*tokens;
	char	**line;

	input = env_vars(input, envi->env_v);
	input = remove_spaces(input);
	tokens = lexer(ft_split(line, ' '));
}