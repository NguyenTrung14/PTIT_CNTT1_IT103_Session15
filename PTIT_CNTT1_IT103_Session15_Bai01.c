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
int main() {
    Queue* queue = createQueue(5);
    free(queue->arr);
    free(queue);
    return 0;
}