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
    if (my_queue->rear == MAXSIZE)
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
    if (my_queue->rear == MAXSIZE)
        return false;
    my_queue->data[my_queue->rear++] = n;
    return true;
}
bool Dequeue(queue *my_queue, int *n)
{
    if (my_queue == NULL || n == NULL || my_queue->front == my_queue->rear)
        return false;
    *n = my_queue->data[my_queue->front];
    my_queue->front++;
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
    *n = my_queue->rear - my_queue->front;
    return true;
}
bool Clear_queue(queue *my_queue)
{
    if (my_queue == NULL)
        return false;
    my_queue->front = my_queue->rear = 0;
    return true;
}
int main()
{
    queue my_queue;
    Init_queue(&my_queue);
}