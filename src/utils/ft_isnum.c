/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:24:17 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:24:18 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		return (true);
	return (false);
}