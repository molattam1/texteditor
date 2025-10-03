#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

typedef struct {
    int *data;
    int size;
    int top;
} Stack;

int stack_init(Stack *s, int initial_size);
int stack_push(Stack *s, int value);
int stack_pop(Stack *s);
void stack_print(Stack *s);
void stack_clean(Stack *s);

#endif /* DYNAMICSTACK_H */
