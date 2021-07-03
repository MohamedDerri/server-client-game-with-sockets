/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:31:28 by mderri            #+#    #+#             */
/*   Updated: 2019/10/09 15:26:47 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nv_mai;

	if (!(nv_mai = (t_list *)ft_memalloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		nv_mai->content = NULL;
		nv_mai->content_size = 0;
	}
	else
	{
		if (!(nv_mai->content = (void *)ft_memalloc(sizeof(void) *
content_size)))
			return (NULL);
		ft_memcpy(nv_mai->content, content, content_size);
		nv_mai->content_size = content_size;
	}
	nv_mai->next = NULL;
	return (nv_mai);
}
