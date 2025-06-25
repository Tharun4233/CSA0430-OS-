#include <fcntl.h>     // For open()
#include <unistd.h>    // For read(), write(), close()
#include <stdio.h>     // For perror()
#include <stdlib.h>    // For exit()

#define BUFFER_SIZE 1024

int main() {
    int source_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // Open the source file for reading
    source_fd = open("source.txt", O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        exit(1);
    }

    // Open or create the destination file with write permission
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(source_fd);
        exit(1);
    }

    // Read from source and write to destination
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }

    // Close both files
    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");

    return 0;
}

