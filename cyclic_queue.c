#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef struct queue
{
    int data[MAXSIZE];
    int front;
    int rear;
} queue;
bool Init_queue(queue *my_queue)
{
    if (my_queue == NULL)
    {
        printf("空指针");
        return false;
    }
    my_queue->front = my_queue->rear = 0;
    return true;
}
bool Isempty(queue *my_queue)
{
    if (my_queue == NULL)
    {
        printf("空指针");
        return false;
    }
    if (my_queue->front == my_queue->rear)
        return true;
    return false;
}
bool Isfull(queue *my_queue)
{
    if (my_queue == NULL)
    {
        printf("空指针");
        return false;
    }
    if ((my_queue->rear + 1) % MAXSIZE == my_queue->front)
        return true;
    return false;
}
bool Enqueue(queue *my_queue, int n)
{
    if (my_queue == NULL)
    {
        printf("空指针");
        return false;
    }
    if ((my_queue->rear + 1) % MAXSIZE == my_queue->front)
        return false;
    my_queue->data[(my_queue->rear++) % MAXSIZE] = n;
    return true;
}
bool Dequeue(queue *my_queue, int *n)
{
    if (my_queue == NULL || n == NULL || my_queue->front == my_queue->rear)
        return false;
    *n = my_queue->data[my_queue->front];
    my_queue->front = (my_queue->front + 1) % MAXSIZE;
    return true;
}
bool Get_front(queue *my_queue, int *n)
{
    if (my_queue == NULL || n == NULL || my_queue->front == my_queue->rear)
        return false;
    *n = my_queue->data[my_queue->front];
    return true;
}
bool Get_Size(queue *my_queue, int *n)
{
    if (my_queue == NULL || n == NULL)
        return false;
    if (my_queue->front <= my_queue->rear)
        *n = my_queue->rear - my_queue->front;
    else
        *n = MAXSIZE - (my_queue->front - my_queue->rear);
    return true;
    //*n = (my_queue->rear - my_queue->front + MAXSIZE) % MAXSIZE;
}
bool Clear_queue(queue *my_queue)
{
    if (my_queue == NULL)
        return false;
    my_queue->front = my_queue->rear = 0;
    return true;
}
bool Print_queue(queue *my_queue)
{
    if (my_queue == NULL)
        return false;
    int p = my_queue->front;
    while (p != my_queue->rear)
    {
        printf("%d ", my_queue->data[p]);
        p = (p + 1) % MAXSIZE;
    }
    return true;
}
int main()
{
    queue my_queue;
    Init_queue(&my_queue);
}