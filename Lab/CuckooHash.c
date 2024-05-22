#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11

// Hash function 1: X % 11
int hashFunction1(int key) {
    return key % 11;
}

// Hash function 2: (X / 11) % 11
int hashFunction2(int key) {
    return (key / 11) % 11;
}

struct CuckooHashing {
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];
};

void initialize(struct CuckooHashing* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table1[i] = -1;
        hashTable->table2[i] = -1;
    }
}

void insert(struct CuckooHashing* hashTable, int key) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);

    if (hashTable->table1[index1] == -1) {
        hashTable->table1[index1] = key;
    } else if (hashTable->table2[index2] == -1) {
        hashTable->table2[index2] = key;
    } else {
        int evictedKey;
        if (rand() % 2 == 0) {
            evictedKey = hashTable->table1[index1];
            hashTable->table1[index1] = key;
        } else {
            evictedKey = hashTable->table2[index2];
            hashTable->table2[index2] = key;
        }
        printf("Cuckoo eviction: Key %d evicted.\n", evictedKey);
        insert(hashTable, evictedKey);
    }
    printf("Key %d inserted successfully.\n", key);
}

int search(struct CuckooHashing* hashTable, int key) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    return (hashTable->table1[index1] == key || hashTable->table2[index2] == key);
}

void removeKey(struct CuckooHashing* hashTable, int key) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);

    if (hashTable->table1[index1] == key) {
        hashTable->table1[index1] = -1;
        printf("Key %d deleted successfully.\n", key);
    } else if (hashTable->table2[index2] == key) {
        hashTable->table2[index2] = -1;
        printf("Key %d deleted successfully.\n", key);
    } else {
        printf("Key %d not found. Unable to delete.\n", key);
    }
}

void display(struct CuckooHashing* hashTable) {
    printf("Hash Table 1: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", hashTable->table1[i]);
    }
    printf("\n");
    printf("Hash Table 2: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", hashTable->table2[i]);
    }
    printf("\n");
}

int main() {
    struct CuckooHashing hashTable;
    initialize(&hashTable);
    int choice, key;
    do {
        printf("\nMenu:\n");
        printf("1. Insert Key\n");
        printf("2. Search Key\n");
        printf("3. Delete Key\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&hashTable, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(&hashTable, key))
                    printf("Key %d found.\n", key);
                else
                    printf("Key %d not found.\n", key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                removeKey(&hashTable, key);
                break;
            case 4:
                display(&hashTable);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
