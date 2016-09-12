//
// Created by jvolonda on 11/09/16.
//

#ifndef SWAP_H
#define SWAP_H

typedef struct      s_pile
{
    int             value;
    struct s_pile   *next;
}                   t_pile;

typedef struct      s_env
{
    struct s_pile   *a;
    struct s_pile   *b;
    struct s_pile   *a_sorted;
    void             (*f)(int);
}                   t_env;

t_env       *get_env();
void        swap_a(int i);
void        swap_b(int i);
void        push_a(int i);
void        push_b(int i);
void        rotate_b(int i);
void        rotate_a(int i);
void        rotate_reverse_a(int i);
void        rotate_reverse_b(int i);
void		merge_sort(t_pile **head_ref, int (*f)(t_pile *a, t_pile *b));
int         value_sort(t_pile *a, t_pile *b);
void        ft_error(char *error);

#endif // SWAP_H
