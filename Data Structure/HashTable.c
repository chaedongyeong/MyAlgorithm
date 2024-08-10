#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        struct Node* temp = hashTable[hashIndex];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(int key) {
    int hashIndex = hashFunction(key);
    struct Node* temp = hashTable[hashIndex];

    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

int main() {
    insert(1, 10);
    insert(2, 20);
    insert(42, 80);
    printf("Value for key 42: %d\n", search(42));
    return 0;
}
