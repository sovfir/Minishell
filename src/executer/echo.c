/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:27:33 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:27:34 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_n(int i, int j, char **input, bool *flag)
{
	if (input[j][i] == '-' && input[j][i + 1] == 'n' && input[j][i + 2] == '\0')
	{
		*flag = true;
		j++;
	}
	return (j);
}

static bool	check_empty(char **input)
{
	if (input[1] == NULL)
	{
		write(1, "\n", 1);
		return (false);
	}
	return (true);
}

void	echo(char **input, t_env_v *env_v)
{
	bool	flag;
	int		i;
	int		j;

	j = 1;
	if (check_empty(input) == false)
		return ;
	flag = false;
	i = 0;
	j = check_n(i, j, input, &flag);
	while (input[j] != NULL)
	{
		i = 0;
		while (input[j][i] != '\0')
		{
			write(1, &input[j][i], 1);
			i++;
		}
		if (input[j + 1] != NULL)
			write(1, " ", 1);
		j++;
	}
	if (flag == false)
		write(1, "\n", 1);
	rep_env(&env_v, ft_strdup("?"), ft_strdup("0"), false);
}
