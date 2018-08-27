/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 05:21:24 by gquerre           #+#    #+#             */
/*   Updated: 2018/08/27 17:41:52 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

/*int	ft_dump(t_env *e)
{
	int	v;

	i = 0;
	if (e->visu > 0)
		ft_end_visu(e);
	while (i < MEM_SIZE)
	{
		v = 0;
		while (i < MEM_SIZE && v < WIDTH_DUMP)
		{
			ft_print_hexa(e->arena[i]);
			if (v < WIDTH_DUMP - 1)
				ft_putchar(' ');
			v++;
			i++;
		}
		ft_putchar('\n');
	}
	return (1);
}*/

void	ft_output_arena(t_env *e)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("%s0x%04x : ", i ? "\n" : "", i);
		printf("%02x ", e->arena[i]);
		i++;
	}
	printf("\n");
	exit(0);
}

int		ft_dump(t_env *corewar)
{
	ft_output_arena(corewar);
	return (0);
}
