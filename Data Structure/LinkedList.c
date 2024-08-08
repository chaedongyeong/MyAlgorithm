#include <stdio.h>
#include <stdlib.h>

// Node 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// LinkedList 구조체 정의
typedef struct {
    Node* head;
} LinkedList;

// LinkedList 초기화
void initLinkedList(LinkedList* list) {
    list->head = NULL;
}

// 새로운 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// LinkedList에 노드 추가 (맨 앞에 추가)
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// LinkedList 출력
void printLinkedList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 노드 삭제 (주어진 값의 노드 삭제)
void deleteNode(LinkedList* list, int data) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// LinkedList 메모리 해제
void freeLinkedList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    list->head = NULL;
}
