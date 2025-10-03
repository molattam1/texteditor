#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamicstack.h"
#include "custominput.h"

char commands[3][10] = {
    "type",
    "undo",
    "redo"
};

int main(void) {
    Stack undo;
    Stack redo;
    stack_init(&undo, 2);
    stack_init(&redo, 2);


    while(1) {
        /* Program Entry */
        printf("> Command: ");
        char* input = read_line(stdin);

        if (strcmp(input, commands[0]) == 0) {
            printf("> Start Typing:\n");
            printf("> ");
            printf("\n");
        }
        else if (strcmp(input, commands[1]) == 0) {
            printf("> Start Typing:\n");
            printf("> ");
            printf("\n");
        }
        else if (strcmp(input, commands[2]) == 0) {
            printf("> Start Typing:\n");
            printf("> ");
            printf("\n");
        }
        else {
            printf("> Unknown command\n");
            printf("Exiting...\n");
            break;
        }

        stack_clean(&undo);
        stack_clean(&redo);
        free(input);
    }
    return 0;
}
