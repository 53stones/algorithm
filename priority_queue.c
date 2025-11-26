#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct queue
{
    int data;
    int priority;
} queue;
typedef struct Link_queue
{
    queue *ele;
    int size;
    int MAX;
} Link_queue;
bool Init_queue(Link_queue **my_queue, int MAX)
{
    if (my_queue == NULL)
        return false;
    (*my_queue) = (Link_queue *)malloc(sizeof(Link_queue));
    if (*my_queue == NULL)
        return false;
    (*my_queue)->ele = (queue *)malloc(MAX * sizeof(queue));
    if ((*my_queue)->ele == NULL)
        return false;
    (*my_queue)->size = 0;
    (*my_queue)->MAX = MAX;
    return true;
}
bool IsEmpty(Link_queue *my_queue)
{
    if (my_queue == NULL || my_queue->ele == NULL)
    {
        printf("空指针");
        return true;
    }
    if (my_queue->size == 0)
        return true;
    return false;
}
bool IsFull(Link_queue *my_queue)
{
    if (my_queue == NULL || my_queue->ele == NULL)
    {
        printf("空指针");
        return false;
    }
    if (my_queue->size == my_queue->MAX)
        return true;
    return false;
}
bool Enqueue(Link_queue *my_queue, int n, int p)
{
    if (my_queue == NULL || my_queue->ele == NULL)
    {
        printf("空指针");
        return false;
    }
    if (my_queue->size == my_queue->MAX)
    {
        printf("队列满");
        return false;
    }
    if (my_queue->size == 0)
    {
        my_queue->ele[my_queue->size].data = n;
        my_queue->ele[my_queue->size].priority = p;
        my_queue->size++;
        return true;
    }
    else
    {
        int i = my_queue->size - 1;
        while (my_queue->ele[i].priority > p)
        {
            my_queue->ele[i + 1] = my_queue->ele[i];
            i--;
        }
        my_queue->ele[i + 1].data = n;
        my_queue->ele[i + 1].priority = p;
        my_queue->size++;
        return true;
    }
}
bool Dequeue(Link_queue *my_queue, int *n, int *p)
{
    if (my_queue == NULL || my_queue->ele == NULL || n == NULL || p == NULL)
    {
        printf("空指针");
        return false;
    }
    if (my_queue->size == 0)
    {
        printf("队列空");
        return false;
    }
    *n = my_queue->ele[0].data;
    *p = my_queue->ele[0].priority;
    if (my_queue->size == 1)
    {
        my_queue->size--;
        return true;
    }
    else
    {
        for (int i = 1; i <= my_queue->size - 1; i++)
        {
            my_queue->ele[i - 1] = my_queue->ele[i];
        }
        my_queue->size--;
        return true;
    }
}
bool Get_Front(Link_queue *my_queue, int *n, int *p)
{
    if (my_queue == NULL || my_queue->ele == NULL || n == NULL || p == NULL)
    {
        printf("空指针");
        return false;
    }
    if (my_queue->size == 0)
    {
        printf("队列空");
        return false;
    }
    *n = my_queue->ele[0].data;
    *p = my_queue->ele[0].priority;
    return true;
}
bool Destroy_queue(Link_queue **my_queue)
{
    if (my_queue == NULL || *my_queue == NULL || (*my_queue)->ele == NULL)
        return false;
    free((*my_queue)->ele);
    free(*my_queue);
    return true;
}
bool Get_Size(Link_queue *my_queue, int *n)
{
    if (my_queue == NULL || my_queue->ele == NULL || n == NULL)
    {
        printf("空指针");
        return false;
    }
    *n = my_queue->size;
    return true;
}
bool Clear_queue(Link_queue *my_queue)
{
    if (my_queue == NULL || my_queue->ele == NULL)
        return false;
    my_queue->size = 0;
    return true;
}
bool Print_queue(Link_queue *my_queue)
{
    if (my_queue == NULL || my_queue->ele == NULL)
        return false;
    for (int i = 0; i < my_queue->size; i++)
    {
        if (i == my_queue->size - 1)
            printf("%d %d", my_queue->ele[i].data, my_queue->ele[i].priority);
        else
            printf("%d %d,", my_queue->ele[i].data, my_queue->ele[i].priority);
    }
    return true;
}
bool Expand_queue(Link_queue *my_queue, int MAX)
{
    if (my_queue == NULL || my_queue->ele == NULL)
    {
        printf("空指针");
        return false;
    }
    if (MAX <= my_queue->MAX)
    {
        printf("异常容量");
        return false;
    }
    queue *p = realloc(my_queue->ele, MAX * sizeof(queue));
    if (p != NULL)
    {
        my_queue->ele = p;
        my_queue->MAX = MAX;
        return true;
    }
    return false;
}
int main()
{
    Link_queue *my_queue;
    int MAX = 100;
    Init_queue(&my_queue, MAX);
}