#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* arr;
    int size;
    int front;
    int rear;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed for queue.\n");
        exit(1);
    }
    queue->arr = (int*)malloc(size * sizeof(int));
    if (!queue->arr) {
        printf("Memory allocation failed for queue array.\n");
        free(queue);
        exit(1);
    }
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, int data) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

void printQueue(Queue* queue) {
    printf("\nQueue contents:\n");
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

int main() {
    Queue* queue = createQueue(5);
    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i);
    }
    int value;
    printf("Enter a value to enqueue: ");
    if (scanf("%d", &value) == 1) {
        enqueue(queue, value);
    } else {
        printf("Invalid input. Please enter an integer.\n");
    }
    printQueue(queue);
    free(queue->arr);
    free(queue);
    return 0;
}
