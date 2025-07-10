#include <stdio.h>
#include <stdlib.h>
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

int dequeue(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = queue->arr[queue->front];
    queue->front++;
    return val;
}

bool checkIncreasing(Queue* queue) {
    if (queue->rear <= queue->front) return true;
    int prev = dequeue(queue);
    while (queue->rear >= queue->front) {
        int curr = dequeue(queue);
        if (curr - prev != 1) return false;
        prev = curr;
    }
    return true;
}

int n, x;

int main() {
    scanf("%d", &n);
    Queue* queue = createQueue(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        enqueue(queue, x);
    }
    if (checkIncreasing(queue)) printf("true");
    else printf("false");
    free(queue->arr);
    free(queue);
    return 0;
}
