#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct list
{
    list *next;
    int data;
} list;
bool Init_list(list **mylist)
{
    (*mylist) = (list *)malloc(sizeof(list));
    if (*mylist == NULL)
        return false;
    (*mylist)->data = 0;
    (*mylist)->next = *mylist;
    return true;
}
bool Isempty_list(list *mylist)
{
    if (mylist == NULL || mylist->next == mylist)
        return true;
    return false;
}
bool Clear_list(list *mylist)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    list *q = mylist->next;
    while (q != p)
    {
        p->next = q->next;
        free(q);
        q = p->next;
    }
    p->next = p;
    return true;
}
bool Insert_list(list *mylist, int i, int n)
{
    if (mylist == NULL || i < 1)
        return false;
    list *p = mylist;
    list *r = (list *)malloc(sizeof(list));
    if (r == NULL)
        return false;
    r->data = n;
    for (int j = 0; j < i - 1; j++)
    {
        p = p->next;
        if (p == mylist)
            return false;
    }
    r->next = p->next;
    p->next = r;
    return true;
}
bool Insert_list_front(list *mylist, int n)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    list *q = (list *)malloc(sizeof(list));
    if (q == NULL)
        return false;
    q->data = n;
    q->next = p->next;
    p->next = q;
    return true;
}
bool Insert_list_behind(list *mylist, int n)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    list *q = (list *)malloc(sizeof(list));
    if (q == NULL)
        return false;
    q->data = n;
    while (p->next != mylist)
        p = p->next;
    q->next = p->next;
    p->next = q;
    return true;
}
bool Print_list(list *mylist)
{
    if (mylist == NULL)
        return false;
    list *p = mylist->next;
    while (p != mylist)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return true;
}
bool Delete_list(list *mylist, int i)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    for (int j = 0; j < i - 1; j++)
    {
        p = p->next;
        if (p == mylist)
            return false;
    }
    list *q = p->next;
    if (q == mylist)
        return false;
    p->next = q->next;
    free(q);
    return true;
}
bool Delete_list_front(list *mylist)
{
    if (mylist == NULL || mylist->next == mylist)
        return false;
    list *p = mylist->next;
    mylist->next = p->next;
    free(p);
    return true;
}
bool Delete_list_behind(list *mylist)
{
    if (mylist == NULL || mylist->next == mylist)
        return false;
    list *p = mylist;
    list *q;
    while (p->next != mylist)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    return true;
}
int Find_values_list(list *mylist, int n)
{
    if (mylist == NULL)
        return -1;
    int i = 0;
    list *p = mylist;
    while (p->next != mylist)
    {
        p = p->next;
        i++;
        if (p->data == n)
            return i;
    }
    return -1;
}
int Find_index_list(list *mylist, int i)
{
    if (mylist == NULL)
        return -1;
    list *p = mylist;
    int n;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p == mylist)
            return -1;
    }
    n = p->data;
    return n;
}
bool Modify_values_list(list *mylist, int n, int m)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    int a = 0;
    while (p->next != mylist)
    {
        p = p->next;
        if (p->data == n)
        {
            a = 1;
            p->data = m;
        }
    }
    return a == 1;
}
bool Modify_index_list(list *mylist, int i, int m)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p == mylist)
            return false;
    }
    p->data = m;
    return true;
}
int main()
{
    list *mylist;
    Init_list(&mylist);
}