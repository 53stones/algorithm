#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct list
{
    list *pre;
    list *next;
    int data;
} list;
void Init_list(list **mylist)
{
    *mylist = (list *)malloc(sizeof(list));
    (*mylist)->data = 0;
    (*mylist)->pre = NULL;
    (*mylist)->next = NULL;
}
bool Clear_list(list *mylist)
{
    if (mylist == NULL)
        return false;
    list *p = mylist->next;
    list *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    mylist->next = NULL;
    return true;
}
bool Insert_list(list *mylist, int i, int n)
{
    if (mylist == NULL || i < 1)
        return false;
    list *p = mylist;
    for (int j = 0; j < i - 1; j++)
    {
        p = p->next;
        if (p == NULL)
            return false;
    }
    list *q = (list *)malloc(sizeof(list));
    if (q == NULL)
        return false;
    q->data = n;
    q->next = p->next;
    q->pre = p;
    if (p->next != NULL)
    {
        p->next->pre = q;
    }
    p->next = q;
    return true;
}
bool Insert_list_front(list *mylist, int n)
{
    if (mylist == NULL)
        return false;
    list *p = (list *)malloc(sizeof(list));
    if (p == NULL)
        return false;
    p->data = n;
    p->pre = mylist;
    p->next = mylist->next;
    if (mylist->next != NULL)
        mylist->next->pre = p;
    mylist->next = p;
    return true;
}
bool Insert_list_behind(list *mylist, int n)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    while (p->next != NULL)
        p = p->next;
    list *q = (list *)malloc(sizeof(list));
    if (q == NULL)
        return false;
    q->data = n;
    q->pre = p;
    q->next = p->next;
    p->next = q;
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
        if (p == NULL)
            return false;
    }
    list *q = p->next;
    if (q == NULL)
        return false;
    if (q->next != NULL)
        q->next->pre = p;
    p->next = q->next;
    free(q);
    return true;
}
bool Delete_list_front(list *mylist)
{
    if (mylist == NULL)
        return false;
    list *p = mylist->next;
    if (p == NULL)
        return false;
    if (p->next != NULL)
        p->next->pre = mylist;
    mylist->next = p->next;
    free(p);
    return true;
}
bool Delete_list_behind(list *mylist)
{
    if (mylist == NULL || mylist->next == NULL)
        return false;
    list *p = mylist;
    while (p->next != NULL)
        p = p->next;
    list *q = p->pre;
    q->next = NULL;
    free(p);
    return true;
}
bool Delete_list_values(list *mylist, int n)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    int a = 0;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->data == n)
        {
            list *q = p->pre;
            q->next = p->next;
            if (p->next != NULL)
                p->next->pre = q;
            free(p);
            p = q;
            a = 1;
        }
    }
    if (a == 1)
        return true;
    return false;
}
int Find_list_values(list *mylist, int n)
{
    if (mylist == NULL)
        return -1;
    int i = 0;
    list *p = mylist;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
        if (p->data == n)
            return i;
    }
    return -1;
}
int Find_list_index(list *mylist, int i)
{
    if (mylist == NULL)
        return -1;
    list *p = mylist;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p == NULL)
            return -1;
    }
    int n = p->data;
    return n;
}
void Print_list_next(list *mylist)
{
    list *p = mylist;
    if (p == NULL)
        return;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    return;
}
void Print_list_pre(list *mylist)
{
    list *p = mylist;
    if (p == NULL)
        return;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p->pre != NULL)
    {
        printf("%d ", p->data);
        p = p->pre;
    }
    return;
}
int Length_list(list *mylist)
{
    if (mylist == NULL)
        return -1;
    int n = 0;
    list *p = mylist;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}
bool Isempty_list(list *mylist)
{
    if (mylist == NULL || mylist->next == NULL)
        return true;
    return false;
}
bool Modify_value_list(list *mylist, int n, int m)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    int a = 0;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->data == n)
        {
            p->data = m;
            a = 1;
        }
    }
    if (a == 1)
        return true;
    return false;
}
bool Modify_index_list(list *mylist, int i, int m)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p == NULL)
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