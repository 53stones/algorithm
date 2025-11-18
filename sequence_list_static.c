#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int length;
} sequence;
void Init_sequence(sequence *list) // 静态分配
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        list->data[i] = 0;
    }
    list->length = 0;
}
void Insert_sequence(sequence *list, int i, int n)
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
void Delete_sequence(sequence *list, int i)
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
void Find_sequence(sequence *list, int n)
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
int Get_value(sequence *list, int i)
{
    if (i < 1 || i > list->length)
        return 0;
    return list->data[i - 1];
}
int Get_length(sequence *list)
{
    return list->length;
}
bool Is_empty(sequence *list)
{
    if (list->length == 0)
        return true;
    return false;
}
bool Is_full(sequence *list)
{
    if (list->length == MAXSIZE)
        return true;
    return false;
}
void clear_sequence(sequence *list) // 也可以直接将length置为0
{
    for (int i = 0; i < list->length; i++)
    {
        list->data[i] = 0;
    }
    list->length = 0;
    return;
}
void Print_sequence(sequence *list)
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
    sequence list;
}