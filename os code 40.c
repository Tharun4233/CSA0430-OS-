#include <stdio.h>
#include <stdlib.h>

// Simulate Linux file permission display
void displayPermissions(int permission) {
    char perms[10];

    // Owner
    perms[0] = (permission & 0400) ? 'r' : '-';
    perms[1] = (permission & 0200) ? 'w' : '-';
    perms[2] = (permission & 0100) ? 'x' : '-';

    // Group
    perms[3] = (permission & 0040) ? 'r' : '-';
    perms[4] = (permission & 0020) ? 'w' : '-';
    perms[5] = (permission & 0010) ? 'x' : '-';

    // Others
    perms[6] = (permission & 0004) ? 'r' : '-';
    perms[7] = (permission & 0002) ? 'w' : '-';
    perms[8] = (permission & 0001) ? 'x' : '-';

    perms[9] = '\0';

    printf("Simulated File Permissions: -%s\n", perms);
}

int main() {
    int permission;

    printf("Enter permission in octal (e.g., 0751 or 644): ");
    scanf("%o", &permission);

    displayPermissions(permission);

    return 0;
}

