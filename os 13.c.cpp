#include <stdio.h>

#define M 5 // Number of memory blocks
#define N 4 // Number of processes

void allocateMemory(int blocks[], int mSize[], int processes[], int strategy) {
    int allocation[N];
    for (int i = 0; i < N; i++) allocation[i] = -1;

    for (int i = 0; i < N; i++) {
        int bestIdx = -1;
        for (int j = 0; j < M; j++) {
            if (mSize[j] >= processes[i]) {
                if (strategy == 1) { // First Fit
                    bestIdx = j;
                    break;
                } else if (strategy == 2) { // Best Fit
                    if (bestIdx == -1 || mSize[j] < mSize[bestIdx])
                        bestIdx = j;
                } else if (strategy == 3) { // Worst Fit
                    if (bestIdx == -1 || mSize[j] > mSize[bestIdx])
                        bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            mSize[bestIdx] -= processes[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[M] = {100, 500, 200, 300, 600};
    int processSize[N] = {212, 417, 112, 426};

    int copy1[M], copy2[M], copy3[M];
    for (int i = 0; i < M; i++) {
        copy1[i] = blockSize[i];
        copy2[i] = blockSize[i];
        copy3[i] = blockSize[i];
    }

    printf("First Fit Strategy:");
    allocateMemory(blockSize, copy1, processSize, 1);

    printf("\nBest Fit Strategy:");
    allocateMemory(blockSize, copy2, processSize, 2);

    printf("\nWorst Fit Strategy:");
    allocateMemory(blockSize, copy3, processSize, 3);

    return 0;
}

