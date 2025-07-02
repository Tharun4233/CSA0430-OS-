#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int disk[MAX_BLOCKS]; // 0 = free, 1 = allocated

typedef struct {
    int indexBlock;
    int dataBlocks[10];
    int blockCount;
} IndexedFile;

// Function to simulate disk block allocation
int allocateBlock() {
	int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            return i;
        }
    }
    return -1; // No free block
}

void createFile(IndexedFile *file) {
    int i;
    printf("Enter number of blocks required for the file (max 10): ");
    scanf("%d", &file->blockCount);

    if (file->blockCount > 10) {
        printf("Too many blocks requested. Max allowed is 10.\n");
        return;
    }

    // Allocate index block
    file->indexBlock = allocateBlock();
    if (file->indexBlock == -1) {
        printf("No free space for index block.\n");
        return;
    }

    // Allocate data blocks
    for (i = 0; i < file->blockCount; i++) {
        int block = allocateBlock();
        if (block == -1) {
            printf("Disk full while allocating data block %d.\n", i + 1);
            file->blockCount = i;  // Set to blocks successfully allocated
            break;
        }
        file->dataBlocks[i] = block;
    }

    printf("\nFile created successfully.\n");
    printf("Index Block: %d\n", file->indexBlock);
    printf("Data Blocks: ");
    for (i = 0; i < file->blockCount; i++) {
        printf("%d ", file->dataBlocks[i]);
    }
    printf("\n");
}

void displayFile(const IndexedFile *file) {
    int i;
    printf("\n--- File Details ---\n");
    printf("Index Block: %d\n", file->indexBlock);
    printf("Block Pointers in Index Block:\n");
    for (i = 0; i < file->blockCount; i++) {
        printf("Index[%d] --> Block %d\n", i, file->dataBlocks[i]);
    }
}

int main() {
	int i;
    IndexedFile file;

    // Initialize disk to all free
    for (i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = 0;
    }

    createFile(&file);
    displayFile(&file);

    return 0;
}

