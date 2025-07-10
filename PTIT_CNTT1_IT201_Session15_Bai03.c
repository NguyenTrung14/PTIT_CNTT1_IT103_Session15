#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int* arr;
    int size;
    int front;
    int rear;
} Queue;
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(size * sizeof(int));
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue* queue, int data) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}
bool isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}
int main() {
    Queue* queue = createQueue(5);
    // for (int i = 1; i <= 5; i++) enqueue(queue, i);
    if (isEmpty(queue)) printf("true");
    else printf("false");
    free(queue->arr);
    free(queue);
    return 0;
}
