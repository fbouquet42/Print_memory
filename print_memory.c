/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:19:37 by fbouquet          #+#    #+#             */
/*   Updated: 2018/10/25 16:45:42 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_put_hexa(int nb) {
	char	*str;

	str = "0123456789abcdef";
	write(1, (str + nb / 16), 1);
	write(1, (str + nb % 16), 1);
}

void	print_space(size_t n) {
	while (n != 16) {
		if ((n % 2))
			write(1, " ", 1);
		write(1, "  ", 2);
		++n;
	}
}

size_t	print_hexa(const unsigned char *addr, size_t size, size_t i) {
	size_t	n;

	n = 0;
	while (n + i != size && n != 16) {
		ft_put_hexa(*(addr + i + n));
		if (n % 2)
			write(1, " ", 1);
		++n;
	}
	return (n);
}

void	print_char(const unsigned char *addr, size_t size, size_t i) {
	size_t	n;

	n = 0;
	while (n != 16 && n + i != size) {
		if (*(addr + i + n) < 32 || *(addr + i + n) > 126)
			write(1, ".", 1);
		else
			write(1, (addr + i + n), 1);
		++n;
	}
}

void	print_memory(const void *addr, size_t size) {
	size_t	i;

	i = 0;
	while (i < size) {
		print_space(print_hexa((const unsigned char*)addr, size, i));
		print_char((const unsigned char*)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}
