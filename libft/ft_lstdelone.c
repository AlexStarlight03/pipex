/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:20:17 by adube             #+#    #+#             */
/*   Updated: 2023/07/24 14:59:05 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_pile *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	(*del)(lst -> content);
	free(lst);
}
