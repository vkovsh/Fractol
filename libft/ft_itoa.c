/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:46:31 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/09 14:15:46 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;

	len = 2;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		check;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	check = 0;
	if (n < 0)
	{
		n *= -1;
		check = 1;
	}
	if ((res = (char *)malloc(len)) == NULL)
		return (NULL);
	res[--len] = '\0';
	if (check)
		res[0] = '-';
	res[--len] = n % 10 + 48;
	while (n /= 10)
		res[--len] = n % 10 + 48;
	return (res);
}
