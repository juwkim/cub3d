/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:02:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:21:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_atoi(const char *nptr)
{
	int	num;
	int	sign;

	sign = 0;
	if (ft_strchr("+-", *nptr) != NULL)
		sign = (*nptr++ == '-');
	num = 0;
	while (ft_isdigit(*nptr) == true)
		num = num * 10 + (*nptr++ - '0');
	_assert(*nptr == '\0', "color includes nonnumeric character\n");
	if (sign == 1)
		return (-num);
	return (num);
}
