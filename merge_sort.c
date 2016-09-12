//
// Created by jvolonda on 11/09/16.
//

#include "swap.h"
#include "libft/includes/libft.h"

int    value_sort(t_pile *a, t_pile *b)
{
    return (a->value < b->value);
}

static t_pile		*sort_list(t_pile *a, t_pile *b, int (*f)(t_pile *a, t_pile *b))
{
    t_pile	*result;

    result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if ((*f)(a, b))
    {
        result = a;
        result->next = sort_list(a->next, b, (*f));
    }
    else
    {
        result = b;
        result->next = sort_list(a, b->next, (*f));
    }
    return (result);
}

static void		list_split(t_pile *src, t_pile **front_ref, t_pile **back_ref)
{
    t_pile	*fast;
    t_pile	*slow;

    if (src == NULL || src->next == NULL)
    {
        *front_ref = src;
        *back_ref = NULL;
    }
    else
    {
        slow = src;
        fast = src->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *front_ref = src;
        *back_ref = slow->next;
        slow->next = NULL;
    }
}

void		merge_sort(t_pile **head_ref, int (*f)(t_pile *a, t_pile *b))
{
    t_pile	*head;
    t_pile	*a;
    t_pile	*b;

    head = *head_ref;
    if ((head == NULL) || (head->next == NULL))
        return ;
    list_split(head, &a, &b);
    merge_sort(&a, (*f));
    merge_sort(&b, (*f));
    *head_ref = sort_list(a, b, (*f));
}

