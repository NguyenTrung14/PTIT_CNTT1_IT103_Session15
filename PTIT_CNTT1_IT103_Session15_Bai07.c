#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    char customers[100][30];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

void enqueue(Queue* queue, char* customer) {
    if (queue->rear - queue->front + 1 >= 100) {
        printf("Hang doi da day\n");
        return;
    }
    queue->rear++;
    strncpy(queue->customers[queue->rear], customer, 30);
    queue->customers[queue->rear][29] = '\0';
    printf("Da them khach\n");
}

void dequeue(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("Khong co khach nao\n");
        return;
    }
    printf("Da phuc vu khach: %s\n", queue->customers[queue->front]);
    queue->front++;
}

void printQueue(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("Khong co khach nao\n");
        return;
    }
    printf("Danh sach khach:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d. %s\n", i - queue->front + 1, queue->customers[i]);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice;
    char customer[30];
    do {
        printf("-----MENU-----\n1.Them khach\n2.Phuc vu khach\n3.Xem danh sach khach\n4.Thoat\nLua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap ten khach: ");
                fgets(customer, sizeof(customer), stdin);
                if (customer[strlen(customer) - 1] == '\n') {
                    customer[strlen(customer) - 1] = '\0';
                }
                enqueue(&queue, customer);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 4);
    return 0;
}
