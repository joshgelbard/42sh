/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:30 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/04 15:19:43 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			main(int argc, char **argv)
{
	char		*buf;

	ft_putendl("Hello 42sh!");
	g_shell = &g_shellinit;
	g_shell->term_fd = 1;
	term_init(&g_shell->term);
	while (1)
	{
		get_next_line(1, &buf);
		ft_putendl(buf);
	}
	argc = 0;
	argv = 0;
	return (0);
}
