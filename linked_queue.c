#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct queue
{
    int data;
    struct queue *next;
} queue;
typedef struct Link_queue
{
    queue *front;
    queue *rear;
} Link_queue;
bool Init_queue(Link_queue *my_queue)
{
    if (my_queue == NULL)
        return false;
    queue *p = (queue *)malloc(sizeof(queue));
    if (p == NULL)
        return false;
    p->next = NULL;
    my_queue->front = my_queue->rear = p;
    return true;
}
bool Isempty(Link_queue *my_queue)
{
    if (my_queue == NULL)
    {
        printf("空指针");
        return true;
    }
    if (my_queue->front == my_queue->rear)
        return true;
    return false;
}
bool Enqueue(Link_queue *my_queue, int n)
{
    if (my_queue == NULL)
        return false;
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
        return false;
    q->data = n;
    q->next = NULL;
    my_queue->rear->next = q;
    my_queue->rear = q;
    return true;
}
bool DeQueue(Link_queue *my_queue, int *n)
{
    if (my_queue == NULL || n == NULL || my_queue->front == my_queue->rear)
        return false;
    *n = my_queue->front->next->data;
    queue *p = my_queue->front->next;
    my_queue->front->next = p->next;
    free(p);
    if (my_queue->front->next == NULL) // 如果要删除唯一节点，需要将尾指针复位
        my_queue->rear = my_queue->front;
    return true;
}
bool Destroy_queue(Link_queue *my_queue)
{
    if (my_queue == NULL)
    {
        printf("空指针\n");
        return false;
    }
    if (my_queue->front == NULL)
        return false;
    queue *p = my_queue->front;
    while (p->next != NULL)
    {
        my_queue->front->next = p->next->next;
        free(p->next);
        p = my_queue->front;
    }
    free(my_queue->front);
    return true;
}
bool GetFront(Link_queue *my_queue, int *n)
{
    if (my_queue == NULL || n == NULL || my_queue->front == NULL)
    {
        printf("空指针\n");
        return false;
    }
    if (my_queue->front->next == NULL)
        return false;
    *n = my_queue->front->next->data;
    return true;
}
bool GetSize(Link_queue *my_queue, int *n)
{
    if (my_queue == NULL || my_queue->front == NULL || n == NULL)
    {
        printf("空指针\n");
        return false;
    }
    queue *p = my_queue->front;
    int count = 0;
    while (p != my_queue->rear)
    {
        count++;
        p = p->next;
    }
    *n = count;
    return true;
}
bool ClearQueue(Link_queue *my_queue)
{
    if (my_queue == NULL || my_queue->front == NULL)
    {
        printf("空指针\n");
        return false;
    }
    queue *p;
    while (my_queue->front->next != NULL)
    {
        p = my_queue->front->next;
        my_queue->front->next = p->next;
        free(p);
    }
    my_queue->rear = my_queue->front;
    return true;
}
bool Print_queue(Link_queue *my_queue)
{
    if (my_queue == NULL || my_queue->front == NULL)
    {
        printf("空指针\n");
        return false;
    }
    queue *p = my_queue->front;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    return true;
}
int main()
{
    Link_queue my_queue;
    Init_queue(&my_queue);
}