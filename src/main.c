/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:30 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/05 23:28:40 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			main(int argc, char **argv)
{
	ft_printf("%s", "Hello 42sh!\n");
	shell_init();
	prompt(g_shell);

	argc = 0;
	argv = 0;
	return (0);
}
