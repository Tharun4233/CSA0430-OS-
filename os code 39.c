#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
	int i;
	int j;
    // Bubble sort for simplicity
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main() {
    int requests[100], n, head, diskSize, totalMovement = 0;
    int i, pos;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (e.g., 200): ");
    scanf("%d", &diskSize);

    // Add head and disk end (last cylinder) to the request list
    requests[n] = head;
    n++;

    sort(requests, n);

    // Find position of head in sorted array
    for (i = 0; i < n; i++) {
        if (requests[i] == head) {
            pos = i;
            break;
        }
    }

    printf("\nDisk Head Movement Order (C-SCAN):\n");

    // Move towards higher cylinder numbers
    for (i = pos; i < n; i++) {
        printf("%d ", requests[i]);
        if (i != pos)
            totalMovement += abs(requests[i] - requests[i - 1]);
    }

    // Move from last to end of disk (if needed)
    if (requests[n - 1] != diskSize - 1) {
        totalMovement += abs((diskSize - 1) - requests[n - 1]);
        printf("%d ", diskSize - 1);
    }

    // Jump from end to beginning (simulate C-SCAN jump)
    totalMovement += (diskSize - 1);  // head jumps to 0
    printf("0 ");

    // Continue from start to before original head position
    for (i = 0; i < pos; i++) {
        printf("%d ", requests[i]);
        if (i == 0)
            totalMovement += requests[i];  // movement from 0 to first request
        else
            totalMovement += abs(requests[i] - requests[i - 1]);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}

