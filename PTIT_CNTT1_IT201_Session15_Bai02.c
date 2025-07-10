#include<stdio.h>
#include<stdlib.h>

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
void printQueue(Queue* queue) {
    printf("array = [");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d", queue->arr[i]);
        if (i != queue->rear) printf(", ");
    }
    printf("]\n");
    printf("front = %d\n", queue->front);
    printf("rear = %d\n", queue->rear);
    printf("capacity = %d\n", queue->size);
}
int val;
int main() {
    Queue* queue = createQueue(5);
    for (int i = 1; i <= 5; i++) enqueue(queue, i);
    scanf("%d", &val);
    enqueue(queue, val);
    printQueue(queue);
    free(queue->arr);
    free(queue);
    return 0;
}
