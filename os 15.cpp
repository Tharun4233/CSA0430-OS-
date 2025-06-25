#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_FILES 5

struct Directory {
    char user[20];
    char files[MAX_FILES][20];
    int fileCount;
};

struct Directory dirs[MAX_USERS];
int userCount = 0;

void createUser(char name[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(dirs[i].user, name) == 0) {
            printf("User already exists!\n");
            return;
        }
    }
    if (userCount < MAX_USERS) {
        strcpy(dirs[userCount].user, name);
        dirs[userCount].fileCount = 0;
        userCount++;
        printf("User directory created.\n");
    } else {
        printf("User directory limit reached!\n");
    }
}

void createFile(char user[], char filename[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(dirs[i].user, user) == 0) {
            for (int j = 0; j < dirs[i].fileCount; j++) {
                if (strcmp(dirs[i].files[j], filename) == 0) {
                    printf("File already exists under user!\n");
                    return;
                }
            }
            if (dirs[i].fileCount < MAX_FILES) {
                strcpy(dirs[i].files[dirs[i].fileCount], filename);
                dirs[i].fileCount++;
                printf("File created under user %s.\n", user);
            } else {
                printf("File limit reached for user!\n");
            }
            return;
        }
    }
    printf("User not found!\n");
}

void displayFiles(char user[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(dirs[i].user, user) == 0) {
            printf("Files under user %s:\n", user);
            for (int j = 0; j < dirs[i].fileCount; j++)
                printf(" - %s\n", dirs[i].files[j]);
            return;
        }
    }
    printf("User not found!\n");
}

int main() {
    int choice;
    char user[20], filename[20];

    while (1) {
        printf("\n1. Create User\n2. Create File\n3. Display Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter new user name: ");
                scanf("%s", user);
                createUser(user);
                break;
            case 2:
                printf("Enter user name: ");
                scanf("%s", user);
                printf("Enter file name: ");
                scanf("%s", filename);
                createFile(user, filename);
                break;
            case 3:
                printf("Enter user name: ");
                scanf("%s", user);
                displayFiles(user);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

