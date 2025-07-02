#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES], recent[MAX_FRAMES];
    int pageCount, frameCount;
    int i, j, k;
    int pageFaults = 0;
    int time = 0;
    int found, lruIndex, minTime;

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);

    printf("Enter the page reference string: ");
    for(i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    // Initialize frames and recent usage
    for(i = 0; i < frameCount; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    printf("\nPage Replacement Process (LRU):\n");

    for(i = 0; i < pageCount; i++) {
        found = 0;

        // Check if page is already in a frame (Page Hit)
        for(j = 0; j < frameCount; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                recent[j] = time++;  // Update access time
                break;
            }
        }

        // Page Fault
        if(!found) {
            pageFaults++;

            // Find an empty frame
            int emptyIndex = -1;
            for(j = 0; j < frameCount; j++) {
                if(frames[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }

            if(emptyIndex != -1) {
                // Use empty frame
                frames[emptyIndex] = pages[i];
                recent[emptyIndex] = time++;
            } else {
                // Find LRU page
                minTime = recent[0];
                lruIndex = 0;
                for(j = 1; j < frameCount; j++) {
                    if(recent[j] < minTime) {
                        minTime = recent[j];
                        lruIndex = j;
                    }
                }

                // Replace LRU page
                frames[lruIndex] = pages[i];
                recent[lruIndex] = time++;
            }

            // Print frame state
            printf("Page %d -> ", pages[i]);
            for(k = 0; k < frameCount; k++) {
                if(frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\n");
        } else {
            printf("Page %d -> No replacement (Hit)\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

