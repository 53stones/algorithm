#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct stack
{
    int data;
    stack *next;
} stack;
bool Init_stack(stack **my_stack)
{
    *my_stack = NULL;
    return true;
}
bool Push_stack(stack **my_stack, int n)
{
    if (my_stack == NULL)
        return false;
    stack *new_stack = (stack *)malloc(sizeof(stack));
    if (new_stack == NULL)
        return false;
    new_stack->data = n;
    new_stack->next = *my_stack;
    *my_stack = new_stack;
    return true;
}
bool Pop_stack(stack **my_stack, int *dat)
{
    if (my_stack == NULL || *my_stack == NULL)
        return false;
    *dat = (*my_stack)->data;
    stack *p = *my_stack;
    *my_stack = (*my_stack)->next;
    free(p);
    return true;
}
bool Gettop_stack(stack *my_stack, int *dat)
{
    if (my_stack == NULL)
        return false;
    *dat = my_stack->data;
    return true;
}
bool Isempty(stack *my_stack)
{
    if (my_stack == NULL)
        return true;
    return false;
}
bool Destroy_stack(stack **my_stack)
{
    if (my_stack == NULL)
        return false;
    stack *p = *my_stack;
    while (p != NULL)
    {
        *my_stack = (*my_stack)->next;
        free(p);
        p = *my_stack;
    }
    return true;
}
bool Traverse_stack(stack *my_stack)
{
    if (my_stack == NULL)
        return false;
    stack *p = my_stack;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return true;
}
int Getsize_stack(stack *my_stack)
{
    int a = 0;
    stack *p = my_stack;
    while (p != NULL)
    {
        a++;
        p = p->next;
    }
    return a;
}
bool Clear_stack(stack **my_stack)
{
    if (my_stack == NULL)
        return false;
    stack *p = *my_stack;
    while (p != NULL)
    {
        *my_stack = (*my_stack)->next;
        free(p);
        p = *my_stack;
    }
    return true;
}
int main()
{
    stack *my_stack;
    Init_stack(&my_stack);
}