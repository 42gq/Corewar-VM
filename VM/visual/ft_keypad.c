/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 06:21:41 by gquerre           #+#    #+#             */
/*   Updated: 2018/08/27 18:10:56 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_key_p(t_env *e)
{
	int	x;
	int	y;

	x = e->vi->win_width;
	y = e->vi->win_height;
	wmove(e->vi->info, 1, 20);
	wclrtoeol(e->vi->info);
	box(e->vi->info, 0, 0);
	wmove(e->vi->info, 1, 20);
	wprintw(e->vi->info, "*PAUSED*");
	wrefresh(e->vi->info);
	while (getch() != 'p')
	{
		getmaxyx(stdscr, e->vi->win_height, e->vi->win_width);
		if (y != e->vi->win_height || x != e->vi->win_width)
		{
			e->visu = 2;
			return (0);
		}
	}
	return (1);
}

int	ft_keypad(t_env *e, int key_pressed)
{
	if (key_pressed == 0)
		return (1);
	key_pressed = getch();
	if (key_pressed == 'p')
		if (ft_key_p(e) == 0)
			return (0);
	if (key_pressed == 'r')
		e->vi->speed = (e->vi->speed == 0) ? -FREQ : 0;
	if (key_pressed == '-' && ((e->vi->speed + FREQ) >= 0) &&
			((e->vi->speed + FREQ) < 1000000))
	{
		if (e->vi->speed + FREQ >= 1000000)
			e->vi->speed += 1000000;
		else
			e->vi->speed += 100000;
	}
	if (key_pressed == '+' && ((e->vi->speed + FREQ) > 0) &&
			((e->vi->speed + FREQ) < 10000001))
	{
		if (e->vi->speed + FREQ > 1000000)
			e->vi->speed -= 1000000;
		else
			e->vi->speed -= 100000;
	}
	return (1);
}
