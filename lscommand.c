#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void print_file_details(const char *path) {
    struct stat file_stat;
    if (stat(path, &file_stat) == -1) {
        perror("stat");
        return;
    }

    printf("File: %s\n", path);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Permissions: %o\n", file_stat.st_mode & 0777);  // Octal representation of permissions
}

int main(int argc, char *argv[]) {
    // Step 1: Set up the directory path
    const char *dir_path = argc > 1 ? argv[1] : ".";

    // Step 2: Open the directory
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;

    // Step 3: Read the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Print the entry name
        printf("Name: %s\n", entry->d_name);

        // Step 4: Optionally print file details (size, permissions, etc.)
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        print_file_details(full_path);
    }

    // Step 5: Close the directory
    closedir(dir);
    return 0;
}

