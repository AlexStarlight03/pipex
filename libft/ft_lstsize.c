/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:12:56 by adube             #+#    #+#             */
/*   Updated: 2023/07/24 14:59:10 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_pile *lst)
{
	int	size;

	size = 1;
	if (!lst)
		return (0);
	while (lst -> next)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}
