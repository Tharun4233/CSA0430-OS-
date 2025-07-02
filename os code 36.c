#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

// Simulated disk block
typedef struct Block {
    int blockNumber;
    struct Block *next;
} Block;

// File structure using linked allocation
typedef struct {
    Block *start;
    Block *end;
    int totalBlocks;
} LinkedFile;

int disk[MAX_BLOCKS] = {0}; // 0 = free, 1 = allocated

// Allocate a free disk block
Block* allocateBlock() {
	int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            Block *newBlock = (Block*)malloc(sizeof(Block));
            newBlock->blockNumber = i;
            newBlock->next = NULL;
            return newBlock;
        }
    }
    return NULL; // Disk full
}

// Create a file using linked allocation
void createLinkedFile(LinkedFile *file) {
    int n, i;
    printf("Enter number of blocks required for the file: ");
    scanf("%d", &n);

    file->start = NULL;
    file->end = NULL;
    file->totalBlocks = 0;

    for (i = 0; i < n; i++) {
        Block *newBlock = allocateBlock();
        if (newBlock == NULL) {
            printf("Disk full. Only %d blocks allocated.\n", file->totalBlocks);
            return;
        }

        if (file->start == NULL) {
            file->start = file->end = newBlock;
        } else {
            file->end->next = newBlock;
            file->end = newBlock;
        }

        file->totalBlocks++;
    }

    printf("File created successfully using linked allocation.\n");
}

// Display the block chain of a file
void displayLinkedFile(const LinkedFile *file) {
    Block *temp = file->start;
    printf("\n--- File Details ---\n");
    printf("Total Blocks: %d\n", file->totalBlocks);

    if (temp == NULL) {
        printf("File is empty.\n");
        return;
    }

    printf("Block Chain: ");
    while (temp != NULL) {
        printf("%d -> ", temp->blockNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
	int i;
    LinkedFile file;

    // Initialize disk as free
    for (i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = 0;
    }

    createLinkedFile(&file);
    displayLinkedFile(&file);

    return 0;
}

