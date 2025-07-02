#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int pageCount, frameCount;
    int i, j, k;
    int pageFaults = 0;
    int nextToReplace = 0;
    int found;

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

    // Initialize all frames to -1 (empty)
    for(i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process (FIFO):\n");

    for(i = 0; i < pageCount; i++) {
        found = 0;

        // Check if page is already in frame
        for(j = 0; j < frameCount; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found, replace the oldest (FIFO)
        if(!found) {
            frames[nextToReplace] = pages[i];
            nextToReplace = (nextToReplace + 1) % frameCount;
            pageFaults++;

            // Print current frame state
            printf("Page %d -> ", pages[i]);
            for(k = 0; k < frameCount; k++) {
                if(frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\n");
        } else {
            // Page hit (no replacement)
            printf("Page %d -> No replacement (Hit)\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

