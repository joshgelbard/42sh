/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:40:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/04 15:19:27 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		term_init(t_term *t)
{
	t->name = getenv("TERM");
	t->fd = open("/dev/tty", O_RDWR);
	tgetent(0, t->name);
	tcgetattr(TERM_FD, &t->normal);
	tcgetattr(TERM_FD, &t->custom);
	t->custom.c_lflag &= ~ICANON;
	t->custom.c_lflag &= ~ECHO;
	t->custom.c_cc[VMIN] = 1;
	t->custom.c_cc[VTIME] = 0;
	tcsetattr(TERM_FD, TCSANOW, &t->custom);
	_term_do("ti");
	_term_do("vs");
}
