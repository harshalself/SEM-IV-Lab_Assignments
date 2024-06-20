#include <stdio.h>
#include <stdlib.h>

// Function to check if a page is present in frames
int isInFrames(int frames[], int num_frames, int page) {
  	int i;
    for ( i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return 1; // Page found in frames
        }
    }
    return 0; // Page not found in frames
}

// FIFO Page Replacement Algorithm
void fifo(int pages[], int num_pages, int num_frames) {
    int frames[num_frames];
    int frame_index = 0;
    int page_faults = 0;
	int i,j;
    // Initialize frames as empty (-1 indicates empty frame)
    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    // Process each page reference
    for (i = 0; i < num_pages; i++) {
        int page = pages[i];

        // Check if page is in frames
        if (!isInFrames(frames, num_frames, page)) {
            frames[frame_index] = page; // Replace page in current frame
            frame_index = (frame_index + 1) % num_frames; // Move to next frame
            page_faults++;
        }

        // Display current frames
        printf("Frames: ");
        for ( j = 0; j < num_frames; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }
	int hits = num_pages-page_faults;
    printf("Total Page Faults : %d\n", page_faults);
    printf("Total Page hits : %d\n", hits);
}

int main() {
    int num_pages;
    int i;
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    int pages[num_pages];
    printf("Enter the page reference sequence: ");
    for (i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    int num_frames;
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    fifo(pages, num_pages, num_frames);

    return 0;
}

