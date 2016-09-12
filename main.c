//
// Created by jvolonda on 11/09/16.
//

#include "swap.h"
#include "libft/includes/libft.h"

int     ft_check(char *s)
{
    int i;

    i = 0;
    while (s[i])
   {
        if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
            return 0;
        i++;
    }
    return 1;
}

t_env    *get_env()
{
    static t_env    *env;
    if (!env) {
        env = (t_env *) malloc(sizeof(t_env));
        env->a = NULL;
        env->b = NULL;
        env->a_sorted = NULL;
    }
    return env;
}

t_pile  *add_to_pile(t_pile *prev, char *str)
{
    t_pile  *next;

    next = (t_pile *)malloc(sizeof(t_pile));
    next->next = prev;
    next->value = ft_atoi(str);
    return next;
}

void    init(char **av, int ac)
{
    t_env *env;

    env = get_env();
    while (ac-- > 1)
    {
        if (!ft_check(av[ac]))
            ft_error("ERROR\n");
        env->a = add_to_pile(env->a, av[ac]);
        env->a_sorted = add_to_pile(env->a_sorted, av[ac]);
    }
    merge_sort(&get_env()->a_sorted, &value_sort);
}

void    print_list(t_pile *pile)
{
    while (pile)
    {
        ft_fprintf(1, "%d ",pile->value);
        pile = pile->next;
    }
    ft_fprintf(1,"\n");
}

int     list_is_sorted(t_pile *pile)
{
    while (pile && pile->next)
    {
        if (pile->value > pile->next->value)
            return 0;
        pile = pile->next;
    }
    return 1;
}

int     do_swap_a()
{
    if (get_env()->a && get_env()->a->next)
        return (get_env()->a->value > get_env()->a->next->value);
    return 0;
}

int     do_push_b()
{
    if (get_env()->a && get_env()->a_sorted && get_env()->a->value == get_env()->a_sorted->value)
    {
        get_env()->a_sorted = get_env()->a_sorted->next;
        return 1;
    }
    return 0;
}

int     count_list()
{
    t_pile  *a;
    int i;

    a = get_env()->a;
    i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return i;
}

int     rotate()
{
    t_pile *a;
    int     value;
    int     count;

    a = get_env()->a;
    count = count_list() / 2;
    value = get_env()->a_sorted->value;
    while (a && count)
    {
        if (a->value == value)
            return 1;
        count--;
        a = a->next;
    }
    return 0;
}

int     loop_sort()
{
//    char tg[2];
//    t_pile *a;
// a chaque iteration swap_a ?
    while (!list_is_sorted(get_env()->a))
    {
//        if(do_swap_a())
//            get_env()->f = &swap_a;
        if (do_push_b())
            get_env()->f = &push_b;
        else if (rotate())
            get_env()->f = &rotate_a;
        else
            get_env()->f = &rotate_reverse_a;
        get_env()->f(1);
//        print_list(get_env()->a);
//        print_list(get_env()->b);
//        print_list(get_env()->a_sorted);
//        read(0, &tg, 2);
    }
    return 1;
}

void    loop_finish()
{
    while (get_env()->b)
        push_a(1);
}

int     main(int ac, char **av)
{
    (void)ac;
    init(av, ac);
    loop_sort();
    loop_finish();
//    ft_fprintf(1, "pile a_sorted: ");
//    print_list(get_env()->a_sorted);
//    ft_fprintf(1, "\npile a: ");
//    print_list(get_env()->a);
//    ft_fprintf(1, "\npile b: ");
//    print_list(get_env()->b);
//    ft_fprintf(1, "\n");
    return 0;
}