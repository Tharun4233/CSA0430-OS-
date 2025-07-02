#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char data[100];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} File;

void insertRecord(File *file) {
    if (file->count >= MAX_RECORDS) {
        printf("File is full. Cannot insert more records.\n");
        return;
    }

    Record newRecord;
    printf("Enter record ID: ");
    scanf("%d", &newRecord.id);
    getchar(); // consume newline
    printf("Enter record data: ");
    fgets(newRecord.data, sizeof(newRecord.data), stdin);
    newRecord.data[strcspn(newRecord.data, "\n")] = '\0'; // remove newline

    file->records[file->count++] = newRecord;
    printf("Record inserted successfully at position %d.\n", file->count - 1);
}

void displayRecords(const File *file) {
	int i;
    if (file->count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- File Records (Sequential Access) ---\n");
    for (i = 0; i < file->count; i++) {
        printf("Record %d: ID = %d, Data = %s\n", i, file->records[i].id, file->records[i].data);
    }
}

void accessRecordSequentially(const File *file, int index) {
	int i;
	
    if (index >= file->count || index < 0) {
        printf("Invalid record index.\n");
        return;
    }

    printf("\nAccessing record at index %d sequentially:\n", index);
    for (i = 0; i <= index; i++) {
        printf("Record %d: ID = %d, Data = %s\n", i, file->records[i].id, file->records[i].data);
    }
}

int main() {
    File myFile;
    myFile.count = 0;
    int choice, index;

    while (1) {
        printf("\n--- Sequential File Allocation Menu ---\n");
        printf("1. Insert Record\n");
        printf("2. Display All Records\n");
        printf("3. Access Record Sequentially\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRecord(&myFile);
                break;
            case 2:
                displayRecords(&myFile);
                break;
            case 3:
                printf("Enter index of record to access: ");
                scanf("%d", &index);
                accessRecordSequentially(&myFile, index);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

