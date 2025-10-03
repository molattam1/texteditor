#include <stdio.h>
#include <stdlib.h>
#include "dynamicstack.h"

int stack_init(Stack *s, int initial_size) {
    s->size = initial_size;
    s->data = malloc(s->size * sizeof(char));
    if(s->data == NULL){
        perror("malloc failed.");
        return 1;
    }
    s->top = -1;
    return 0;
}

int stack_push(Stack *s, char value) {
    if(s->top + 1 >= s->size) {
        char *temp;
        int newSize = s->size * 2;
        temp = realloc(s->data, newSize * sizeof(char));
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
    return 0;  // ← Returns 0 (success), NOT the value!
}

void stack_print(Stack *s) {
    printf("=== Stack Top ===\n[");
    for(int i = 0; i <= s->top; i++) {
        printf("%c", s->data[i]);
    }
    printf("]\n=== Stack End ===\n");
}

void stack_clean(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->top = -1;
}

void stack_top_to_bottom(Stack *s1, Stack *s2, int times) {
    for (int i = 0; i < times; i++) {
        if (stack_isEmpty(s1)) {
            break;
        }
        char value = stack_peek(s1);
        stack_push(s2, value);
        stack_pop(s1);
    }
}

char stack_peek(Stack *s) {
    if(stack_isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}
