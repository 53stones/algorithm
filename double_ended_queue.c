#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct double_ended_queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
} queue;
bool Init_queue(queue **q)
{
    if (q == NULL)
    {
        printf("传入空指针\n");
        return false;
    }
    (*q) = (queue *)malloc(sizeof(queue));
    if (*q == NULL)
    {
        printf("动态分配失败\n");
        return false;
    }
    (*q)->front = 0;
    (*q)->rear = 0;
    return true;
}
bool Is_Empty(queue *q)
{
    if (q == NULL)
    {
        printf("空指针");
        return true;
    }
    if (q->front == q->rear)
        return true;
    return false;
}
bool Full_Queue(queue *q)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if ((q->rear + 1) % MAX_SIZE == q->front)
        return true;
    return false;
}
bool Clear_Queue(queue *q)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    q->front = 0;
    q->rear = 0;
    return true;
}
bool Destroy_Queue(queue **q)
{
    if (q == NULL || (*q) == NULL)
    {
        printf("空指针");
        return false;
    }
    free(*q);
    *q = NULL;
    return true;
}
bool Front_Insert(queue *q, int n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if ((q->rear + 1) % MAX_SIZE == q->front)
        return false;
    q->data[(q->front + MAX_SIZE - 1) % MAX_SIZE] = n;
    q->front = (q->front + MAX_SIZE - 1) % MAX_SIZE;
    return true;
}
bool Rear_Insert(queue *q, int n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if ((q->rear + 1) % MAX_SIZE == q->front)
        return false;
    q->data[q->rear] = n;
    q->rear = (q->rear + 1) % MAX_SIZE;
    return true;
}
bool Front_Delete(queue *q, int *n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if (q->front == q->rear)
        return false;
    *n = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return true;
}
bool Rear_Delete(queue *q, int *n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if (q->front == q->rear)
        return false;
    *n = q->data[(q->rear - 1 + MAX_SIZE) % MAX_SIZE];
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return true;
}
bool Get_Front(queue *q, int *n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if (q->front == q->rear)
        return false;
    *n = q->data[q->front];
    return true;
}
bool Get_Rear(queue *q, int *n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    if (q->front == q->rear)
        return false;
    *n = q->data[(q->rear - 1 + MAX_SIZE) % MAX_SIZE];
    return true;
}
bool Get_Length(queue *q, int *n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    int length = 0;
    int p = q->front;
    while (p != q->rear)
    {
        length++;
        p = (p + 1) % MAX_SIZE;
    }
    *n = length;
    return true;
}
bool Print_queue(queue *q)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    int p = q->front;
    while (p != q->rear)
    {
        printf("%d\n", q->data[p]);
        p = (p + 1) % MAX_SIZE;
    }
    return true;
}
bool Find_queue(queue *q, int n)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    int p = q->front;
    while (p != q->rear)
    {
        if (q->data[p] == n)
            return true;
        p = (p + 1) % MAX_SIZE;
    }
    return false;
}
bool Replace_Queue(queue *q, int n, int m)
{
    if (q == NULL)
    {
        printf("空指针");
        return false;
    }
    int p = q->front;
    int is = 0;
    while (p != q->rear)
    {
        if (q->data[p] == n)
        {
            is = 1;
            q->data[p] = m;
        }
        p = (p + 1) % MAX_SIZE;
    }
    if (is == 1)
        return true;
    return false;
}
int main()
{
    queue *q = NULL;
    Init_queue(&q);
}