/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:23:41 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:23:43 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	int		len;

	len = count * size;
	c = malloc(len);
	if (c == NULL)
		return (NULL);
	while (len > 0)
	{
		c[len - 1] = 0;
		len--;
	}
	return (c);
}
