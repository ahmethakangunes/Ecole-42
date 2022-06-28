/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:00:16 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 12:01:36 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *new;
    int temp = 0;

    new = lst;
    while(lst->next != 0)
    {
        if(((*cmp)(lst->data, lst->next->data)) == 0)
        {
            temp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = temp;
            lst = new;
        }
        else
            lst = lst->next;
    }
    lst = new;
    return (lst);
}