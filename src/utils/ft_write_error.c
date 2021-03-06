/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:25:57 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:25:58 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_write_error(char *command, char *arg, char *error)
{
	write(2, RED, ft_strclen(RED, '\0'));
	write(2, "minishell: ", 11);
	if (command != NULL)
	{
		write(2, command, ft_strclen(command, '\0'));
		write(2, ": ", 2);
	}
	if (arg != NULL)
	{
		write(2, arg, ft_strclen(arg, '\0'));
		write(2, ": ", 2);
	}
	write(2, error, ft_strclen(error, '\0'));
	write(2, "\n", 1);
	write(2, RESETCOLOR, ft_strclen(RESETCOLOR, '\0'));
}
