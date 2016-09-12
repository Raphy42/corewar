//
// Created by jvolonda on 11/09/16.
//

#include "libft/includes/libft.h"
#include "swap.h"


//rra : reverse rotate a - décale d’une position vers le bas tous les élements de
//        la pile a. Le dernier élément devient le premier.
//rrb : reverse rotate b - décale d’une position vers le bas tous les élements de
//        la pile b. Le dernier élément devient le premier.
//rrr : rra et rrb en même temps.


void        rotate_reverse_b(int i)
{
    t_pile  *b;

    b = get_env()->b;
    while (b)
    {
        if (b->next && !b->next->next)
        {
            b->next->next = get_env()->b;
            get_env()->b = b->next;
            b->next = NULL;
        }
        b = b->next;
    }
    if (i)
        ft_fprintf(1, "rra");

}

void        rotate_reverse_a(int i)
{
    t_pile  *a;

    a = get_env()->a;
    while (a)
    {
        if (a->next && !a->next->next)
        {
            a->next->next = get_env()->a;
            get_env()->a = a->next;
            a->next = NULL;
        }
        a = a->next;
    }
    if (i)
        ft_fprintf(1, "rra");

}

void        rotate_a(int i)
{
    t_pile  *a;
    int     tmp;

    a = get_env()->a;
    tmp = a->value;
    while (a)
    {
        if (a->next)
            a->value = a->next->value;
        else
            a->value = tmp;
        a = a->next;
    }
    if (i)
        ft_fprintf(1, "ra\n");

}

void        rotate_ab()
{
    rotate_a(0);
    rotate_b(0);
    ft_fprintf(1, "rr");
}

void        rotate_b(int i)
{
    t_pile  *b;
    int     tmp;

    b = get_env()->b;
    tmp = b->value;
    while (b)
    {
        if (b->next)
            b->value = b->next->value;
        else
            b->value = tmp;
        b = b->next;
    }
    if (i)
        ft_fprintf(1, "rb");

}

void        swap_a(int i)
{
    t_pile  *a;
    int     tmp;

    a = get_env()->a;

    if (a && a->next)
    {
        tmp = a->value;
        a->value = a->next->value;
        a->next->value = tmp;
        if (i)
            ft_fprintf(1, "sa\n");
    }
}

void        swap_b(int i)
{
    t_pile  *b;
    int     tmp;

    b = get_env()->b;

    if (b && b->next)
    {
        tmp = b->value;
        b->value = b->next->value;
        b->next->value = tmp;
        if (i)
            ft_fprintf(1, "sb\n");
    }
}

void        swap_ab()
{
    swap_a(0);
    swap_b(0);
    ft_fprintf(1, "ss");
}

void        push_a(int i)
{
    t_pile  *a;
    t_pile  *b;

    a = get_env()->a;
    b = get_env()->b;

    if (b)
    {
        get_env()->b = b->next;
        b->next = a;
        get_env()->a = b;
        if (i)
            ft_fprintf(1, "pa\n");
    }
}

void        push_b(int i)
{
    t_pile  *a;
    t_pile  *b;

    a = get_env()->a;
    b = get_env()->b;

    if (a)
    {
        get_env()->a = a->next;
        a->next = b;
        get_env()->b = a;
        if (i)
            ft_fprintf(1, "pb\n");
    }
}