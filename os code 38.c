#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
	int i;
	int j;
    // Simple bubble sort
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
    int requests[100], n, head, i, direction;
    int diskSize, totalMovement = 0;

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

    printf("Enter direction (0 = towards 0, 1 = towards end): ");
    scanf("%d", &direction);

    // Add head to the request list for sorting
    requests[n] = head;
    n++;

    sort(requests, n);

    // Find position of head in sorted array
    int pos;
    for (i = 0; i < n; i++) {
        if (requests[i] == head) {
            pos = i;
            break;
        }
    }

    printf("\nDisk Head Movement Order:\n");

    if (direction == 1) {
        // Move right (toward max)
        for (i = pos; i < n; i++) {
            printf("%d ", requests[i]);
            if (i != pos) totalMovement += abs(requests[i] - requests[i - 1]);
        }
        // Move to end of disk
        if (requests[n-1] != diskSize - 1) {
            totalMovement += abs((diskSize - 1) - requests[n - 1]);
            printf("%d ", diskSize - 1);
        }
        // Reverse and move left
        for (i = pos - 1; i >= 0; i--) {
            printf("%d ", requests[i]);
            totalMovement += abs(requests[i + 1] - requests[i]);
        }
    } else {
        // Move left (toward 0)
        for (i = pos; i >= 0; i--) {
            printf("%d ", requests[i]);
            if (i != pos) totalMovement += abs(requests[i] - requests[i + 1]);
        }
        // Move to 0 if not already
        if (requests[0] != 0) {
            totalMovement += abs(requests[0] - 0);
            printf("0 ");
        }
        // Reverse and move right
        for (i = pos + 1; i < n; i++) {
            printf("%d ", requests[i]);
            totalMovement += abs(requests[i] - requests[i - 1]);
        }
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}

