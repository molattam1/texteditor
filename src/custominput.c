#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_line(FILE* stream) {
    size_t capacity = 128;  // Initial size
    size_t length = 0;
    char* buffer = malloc(capacity);

    if (!buffer) return NULL;

    while (fgets(buffer + length, capacity - length, stream)) {
        length += strlen(buffer + length);

        // If we found a newline, we're done
        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';  // Remove newline
            return buffer;
        }

        // Need more space - double the capacity
        capacity *= 2;
        char* new_buffer = realloc(buffer, capacity);
        if (!new_buffer) {
            free(buffer);
            return NULL;
        }
        buffer = new_buffer;
    }

    // Handle EOF or error
    if (length == 0) {
        free(buffer);
        return NULL;
    }

    return buffer;
}
