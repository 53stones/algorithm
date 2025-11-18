#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
} list;
bool Init_list(list **mylist)
{
    *mylist = (list *)malloc(sizeof(list));
    if (*mylist == NULL)
        return false;
    (*mylist)->next = NULL;
    (*mylist)->data = 0;
    return true;
}
void Free_list(list *mylist)
{
    free(mylist);
}
bool Insert_list(list *mylist, int i, int n)
{
    if (i < 1 || mylist == NULL)
        return false;
    list *p;
    p = mylist;
    for (int j = 0; j < i - 1; j++)
    {
        p = p->next;
    } // 指向插入前的位置
    if (p == NULL)
        return false;
    list *s = (list *)malloc(sizeof(list));
    s->data = n;
    s->next = p->next;
    p->next = s;
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
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->next = NULL;
    return true;
}
bool Delete_list(list *mylist, int i)
{
    if (i < 1 || mylist == NULL)
        return false;
    list *p = mylist;
    for (int j = 0; j < i - 1; j++)
    {
        if (p == NULL)
            return false;
        p = p->next;
    }
    if (p == NULL || p->next == NULL)
        return false;
    list *s = p->next;
    p->next = s->next;
    free(s);
    return true;
}
bool Delete_list_front(list *mylist)
{
    if (mylist == NULL || mylist->next == NULL)
        return false;
    list *p = mylist->next;
    mylist->next = p->next;
    free(p);
    return true;
}
bool Delete_list_behind(list *mylist)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    list *q = p;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    return true;
}
bool Find_value_list(list *mylist, int n)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    while (p->next != NULL)
    {
        if (p->next->data == n)
            return true;
        p = p->next;
    }
    return false;
}
bool Find_index_list(list *mylist, int i, int *e)
{
    if (i < 1 || mylist == NULL)
        return false;
    list *p = mylist;
    for (int j = 0; j < i; j++)
    {
        if (p == NULL)
            return false;
        p = p->next;
    }
    if (p == NULL)
        return false;
    *e = p->data;
    return true;
}
bool Modify_value_list(list *mylist, int n, int m)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    while (p->next != NULL)
    {
        if (p->next->data == n)
        {
            p->next->data = m;
            return true;
        }
        p = p->next;
    }
    return false;
}
bool Modify_index_list(list *mylist, int i, int n)
{
    if (mylist == NULL || i < 1)
        return false;
    list *p = mylist;
    for (int j = 0; j < i; j++)
    {
        if (p == NULL)
            return false;
        p = p->next;
    }
    if (p == NULL)
        return false;
    p->data = n;
    return true;
}
bool Print_list(list *mylist)
{
    if (mylist == NULL)
        return false;
    list *p = mylist;
    while (p->next != NULL)
    {
        printf("%d ", (p->next)->data);
        p = p->next;
    }
    return true;
}
int Length_list(list *mylist)
{
    if (mylist == NULL)
        return 0;
    int length = 0;
    list *p = mylist;
    while (p->next != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}
bool Is_empty_list(list *mylist)
{
    if (mylist == NULL)
        return true;
    else if (mylist->next == NULL)
        return true;
    else
        return false;
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
int main()
{
    list *mylist;
    Init_list(&mylist);
}