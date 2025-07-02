#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int findOptimalIndex(int pages[], int frames[], int pageCount, int frameCount, int currentIndex) {
    int farthest = currentIndex;
    int indexToReplace = -1;
    int i, j;

    for(i = 0; i < frameCount; i++) {
        int found = 0;
        for(j = currentIndex + 1; j < pageCount; j++) {
            if(frames[i] == pages[j]) {
                if(j > farthest) {
                    farthest = j;
                    indexToReplace = i;
                }
                found = 1;
                break;
            }
        }
        // If frame not found in future, replace this one
        if(!found) {
            return i;
        }
    }

    // If all frames are found in the future
    return (indexToReplace == -1) ? 0 : indexToReplace;
}

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int pageCount, frameCount;
    int i, j, k;
    int pageFaults = 0;
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

    // Initialize frames to -1 (empty)
    for(i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process (Optimal):\n");

    for(i = 0; i < pageCount; i++) {
        found = 0;

        // Check if page is already in frame
        for(j = 0; j < frameCount; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            pageFaults++;

            // Try to find an empty frame
            int emptyIndex = -1;
            for(j = 0; j < frameCount; j++) {
                if(frames[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }

            if(emptyIndex != -1) {
                frames[emptyIndex] = pages[i];
            } else {
                int replaceIndex = findOptimalIndex(pages, frames, pageCount, frameCount, i);
                frames[replaceIndex] = pages[i];
            }

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
            printf("Page %d -> No replacement (Hit)\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

