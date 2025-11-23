#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct stack
{
    int data[MAXSIZE];
    int top_left;
    int top_right;
    int Max;
} stack;
bool Init_mystack(stack **my_stack)
{
    if (my_stack == NULL || *my_stack == NULL)
        return false;
    (*my_stack)->top_left = -1;
    (*my_stack)->top_right = MAXSIZE;
    (*my_stack)->Max = MAXSIZE;
    return true;
}
bool Push_left(stack *my_stack, int n)
{
    if (my_stack == NULL || my_stack->top_left + 1 == my_stack->top_right)
        return false;
    my_stack->top_left++;
    my_stack->data[my_stack->top_left] = n;
    return true;
}
bool Push_right(stack *my_stack, int n)
{
    if (my_stack == NULL || my_stack->top_left + 1 == my_stack->top_right)
        return false;
    my_stack->top_right--;
    my_stack->data[my_stack->top_right] = n;
    return true;
}
bool Pop_left(stack *my_stack, int *ele)
{
    if (my_stack == NULL || my_stack->top_left == -1 || ele == NULL)
        return false;
    *ele = my_stack->data[my_stack->top_left];
    my_stack->top_left--;
    return true;
}
bool Pop_right(stack *my_stack, int *ele)
{
    if (my_stack == NULL || my_stack->top_right == MAXSIZE || ele == NULL)
        return false;
    *ele = my_stack->data[my_stack->top_right];
    my_stack->top_right++;
    return true;
}
bool Top_left(stack *my_stack, int *ele)
{
    if (my_stack == NULL || my_stack->top_left == -1 || ele == NULL)
        return false;
    *ele = my_stack->data[my_stack->top_left];
    return true;
}
bool Top_right(stack *my_stack, int *ele)
{
    if (my_stack == NULL || my_stack->top_right == MAXSIZE || ele == NULL)
        return false;
    *ele = my_stack->data[my_stack->top_right];
    return true;
}
bool Isempty_left(stack *my_stack)
{
    if (my_stack == NULL)
    {
        printf("空指针");
        return false;
    }
    else if (my_stack->top_left == -1)
        return true;
    return false;
}
bool Isempty_right(stack *my_stack)
{
    if (my_stack == NULL)
    {
        printf("空指针");
        return false;
    }
    else if (my_stack->top_right == MAXSIZE)
        return true;
    return false;
}
bool Size_left(stack *my_stack, int *count)
{
    if (my_stack == NULL || count == NULL)
        return false;
    *count = my_stack->top_left + 1;
    return true;
}
bool Size_right(stack *my_stack, int *count)
{
    if (my_stack == NULL || count == NULL)
        return false;
    *count = MAXSIZE - my_stack->top_right;
    return true;
}
bool Isfull(stack *my_stack)
{
    if (my_stack == NULL)
    {
        printf("空指针");
        return false;
    }
    else if (my_stack->top_left + 1 == my_stack->top_right)
        return true;
    return false;
}
bool Clear_left(stack *my_stack)
{
    if (my_stack == NULL)
        return false;
    my_stack->top_left = -1;
    return true;
}
bool Clear_right(stack *my_stack)
{
    if (my_stack == NULL)
        return false;
    my_stack->top_right = MAXSIZE;
    return true;
}
bool Clear_all(stack *my_stack)
{
    if (my_stack == NULL)
        return false;
    my_stack->top_left = -1;
    my_stack->top_right = MAXSIZE;
    return true;
}
int main()
{
    stack *my_stack;
    Init_stack(&my_stack);
}