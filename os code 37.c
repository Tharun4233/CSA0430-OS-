#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[100], n, head, i;
    int totalMovement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Request Sequence: ");
    for (i = 0; i < n; i++) {
        printf("%d ", request[i]);
    }
    printf("\n");

    printf("\nHead Movement:\n");
    for (i = 0; i < n; i++) {
        int movement = abs(head - request[i]);
        printf("Move from %d to %d --> %d cylinders\n", head, request[i], movement);
        totalMovement += movement;
        head = request[i];
    }

    printf("\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}

