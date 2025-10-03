#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamicstack.h"
#include "custominput.h"

char commands[5][10] = {
    "type",
    "undo",
    "redo",
    "show",
    "exit"
};

int main(void) {
    Stack undo;
    Stack redo;
    stack_init(&undo, 2);
    stack_init(&redo, 2);

    while(1) {
        /* Program Entry */
        printf("Text Editor - Commands: type, undo, redo, exit\n");
        printf("> Command: ");
        char* input = read_line(stdin);

        if (strcmp(input, commands[0]) == 0) {
            printf("> Start Typing:\n");
            printf("> ");
            char *content = read_line(stdin);

            // Clear redo stack when new content is typed
            while (!stack_isEmpty(&redo)) {
                stack_pop(&redo);
            }

            for (int i = 0; content[i] != '\0'; i++) {
                stack_push(&undo, content[i]);
            }
            stack_print(&undo);
            printf("\n\n");
            free(content);
        } else if (strcmp(input, commands[1]) == 0) {
            if (!stack_isEmpty(&undo)) {
                char ch = stack_peek(&undo);
                stack_pop(&undo);
                stack_push(&redo, ch);
                stack_print(&undo);
                printf("> Undo done: removed '%c'\n", ch);
            } else {
                printf("> Nothing to undo\n");
            }
        } else if (strcmp(input, commands[2]) == 0) {
            if (!stack_isEmpty(&redo)) {
                char ch = stack_peek(&redo);
                stack_pop(&redo);
                stack_push(&undo, ch);
                stack_print(&undo);
                printf("> Redo done: restored '%c'\n", ch);
            } else {
                printf("> Nothing to redo\n");
            }
        } else if (strcmp(input, commands[3]) == 0) {
            stack_print(&undo);
        } else if (strcmp(input, commands[4]) == 0) {
            printf("> Exiting...\n");
            break;
        }  else {
            printf("> Unknown command...\n");
        }

        free(input);
    }

    stack_clean(&undo);
    stack_clean(&redo);

    return 0;
}
