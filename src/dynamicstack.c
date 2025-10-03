#include <stdio.h>
#include <stdlib.h>
#include "dynamicstack.h"

int stack_init(Stack *s, int initial_size) {
    s->size = initial_size;
    s->data = malloc(s->size * sizeof(int));
    if(s->data == NULL){
        perror("malloc failed.");
    }
    s->top = -1;
    return 0;
}

int stack_push(Stack *s, int value) {
    if(s->top + 1 >= s->size) {
        int *temp;
        int newSize = s->size * 2;
        temp = realloc(s->data, newSize * sizeof(int));
        if(temp == NULL) {
            perror("realloc failed.");
            return 1;
        }
        s->data = temp;
        s->size = newSize;

        printf("allocated extra memory region.\n");
        printf("stack size is now: %d\n", s->size);
    }

    s->top++;
    s->data[s->top] = value;
    return 0;
}

int stack_isEmpty(Stack *s) {
    return s->top == -1;
}

int stack_pop(Stack *s) {
    if(stack_isEmpty(s)) {
        printf("stack is already empty cannot pop.\n");
        return -1;
    }
    s->top--;
    return 0;
}

void stack_print(Stack *s) {
    printf("=== Stack ===\n");
    for(int i = s->top; i > -1; i--) {
        printf("%d\n", s->data[i]);
    }
    printf("=== END ===\n");
}

void stack_clean(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->top = -1;
}
