#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int *data;
    int length;
} list;
void Init_list(list *list) // 动态分配
{
    list->data = (int *)malloc(sizeof(int) * MAXSIZE);
    if (list->data == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    list->length = 0;
}
void ReInit_list(list *list, int n)
{
    if (n < list->length)
        return;
    int *temp = list->data;
    list->data = (int *)malloc(sizeof(int) * n);
    if (list->data == NULL)
    {
        list->data = temp;
        printf("内存分配失败\n");
        return;
    }
    for (int i = 0; i < list->length; i++)
    {
        list->data[i] = temp[i];
    }
    free(temp);
}
void Destroy_list(list *list)
{
    if (list->data != NULL)
    {
        free(list->data);
        list->data = NULL;
    }
    list->length = 0;
}
void Insert_list(list *list, int i, int n)
{
    if (i < 1 || i > list->length + 1)
        return;
    if (list->length >= MAXSIZE)
        return;
    for (int j = list->length - 1; j >= i - 1; j--)
    {
        list->data[j + 1] = list->data[j];
    }
    list->data[i - 1] = n;
    list->length++;
    return;
}
void Delete_list(list *list, int i)
{
    if (i < 1 || i > list->length)
        return;
    for (int j = i - 1; j < list->length - 1; j++)
    {
        list->data[j] = list->data[j + 1];
    }
    list->length--;
    return;
}
void Find_list(list *list, int n)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i] == n)
        {
            printf("%d\n", i + 1);
            return;
        }
    }
    printf("Not found\n");
    return;
}
int Get_value(list *list, int i)
{
    if (i < 1 || i > list->length)
        return 0;
    return list->data[i - 1];
}
int Get_length(list *list)
{
    return list->length;
}
bool Is_empty(list *list)
{
    if (list->length == 0)
        return true;
    return false;
}
bool Is_full(list *list)
{
    if (list->length == MAXSIZE)
        return true;
    return false;
}
void Clear_list(list *list) // 动态分配只需设置length=0
{
    list->length = 0;
}
void Print_list(list *list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return;
}
int main()
{
    list mylist;
}