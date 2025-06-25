#include <stdio.h>
#include <string.h>

#define MAX 10

char files[MAX][20];
int count = 0;

void createFile(char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(name, files[i]) == 0) {
            printf("File already exists!\n");
            return;
        }
    }
    if (count < MAX) {
        strcpy(files[count], name);
        count++;
        printf("File created successfully.\n");
    } else {
        printf("Directory is full!\n");
    }
}

void deleteFile(char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(name, files[i]) == 0) {
            for (int j = i; j < count - 1; j++)
                strcpy(files[j], files[j + 1]);
            count--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void displayFiles() {
    if (count == 0) {
        printf("Directory is empty.\n");
    } else {
        printf("Files in directory:\n");
        for (int i = 0; i < count; i++)
            printf("%s\n", files[i]);
    }
}

int main() {
    int choice;
    char name[20];

    while (1) {
        printf("\n1. Create File\n2. Delete File\n3. Display Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name to create: ");
                scanf("%s", name);
                createFile(name);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                deleteFile(name);
                break;
            case 3:
                displayFiles();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

