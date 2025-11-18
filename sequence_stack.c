#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct stack
{
    int data[MAXSIZE];
    int top;
} stack;
void Init_stack(stack *mystack)
{
    mystack->top = -1;
}
bool Isempty_stack(stack *mystack)
{
    if (mystack == NULL || mystack->top == -1)
        return true;
    return false;
}
bool Isfull_stack(stack *mystack)
{
    if (mystack == NULL)
        return false;
    if (mystack->top == MAXSIZE - 1)
        return true;
    return false;
}
bool Push_stack(stack *mystack, int n)
{
    if (mystack == NULL || mystack->top == MAXSIZE - 1)
        return false;
    mystack->data[mystack->top + 1] = n;
    mystack->top++;
    return true;
}
bool Pop_stack(stack *mystack, int *n)
{
    if (mystack == NULL || mystack->top == -1)
        return false;
    *n = mystack->data[mystack->top];
    mystack->top--;
    return true;
}
bool GetTop_stack(stack *mystack, int *n)
{
    if (mystack == NULL || mystack->top == -1)
        return false;
    *n = mystack->data[mystack->top];
    return true;
}
bool Clear_stack(stack *mystack)
{
    if (mystack == NULL)
        return false;
    mystack->top = -1;
    return true;
}
bool GetLength_stack(stack *mystack, int *n)
{
    if (mystack == NULL)
        return false;
    *n = mystack->top + 1;
    return true;
}
bool Print_stack(stack *mystack)
{
    if (mystack == NULL || mystack->top == -1)
        return false;
    for (int j = 0; j <= mystack->top; j++)
    {
        printf("%d ", mystack->data[j]);
    }
    return true;
}
int main()
{
    stack mystack;
    Init_stack(&mystack);
}