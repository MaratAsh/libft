/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:04 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/05 14:18:52 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *s)
{
	size_t	sz;

	sz = 0;
	while (s[sz])
		sz++;
	return (sz);
}
