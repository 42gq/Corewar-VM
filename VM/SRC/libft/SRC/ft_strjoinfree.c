/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 01:19:31 by gquerre           #+#    #+#             */
/*   Updated: 2018/02/14 04:32:22 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*mem;

	mem = NULL;
	if (!(s2))
		return (s1);
	mem = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (mem);
}
