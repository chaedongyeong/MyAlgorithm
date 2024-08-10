#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Queue {
    int front, rear, size;
    int arr[MAX];
};

void initQueue(struct Queue* queue) {
    queue->front = queue->size = 0;
    queue->rear = MAX - 1;
}

int isFull(struct Queue* queue) {
    return queue->size == MAX;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return item;
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    printf("%d dequeued from queue\n", dequeue(&queue));
    return 0;
}
