/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 01:24:38 by ashulha           #+#    #+#             */
/*   Updated: 2019/01/30 16:32:34 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ant(t_lem *all, int n)
{
	int ants;

	if (n == (all->p_index + all->ants + 1))
		return ;
	ants = all->ants + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= all->p_index)
		{
				ft_putchar('L');
				ft_putnbr(ants);
				ft_putchar('-');
				ft_putstr(all->name[all->path[n - ants]]);
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	print_ant(all, ++n);
}

void		print_all(t_lem *all)
{
	print_ant(all, 2);
}
