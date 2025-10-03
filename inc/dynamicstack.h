#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

typedef struct {
    int *data;
    int size;
    int top;
} Stack;

int init_stack(Stack *s, int initial_size);
int push(Stack *s, int value);
int pop(Stack *s);
void print_stack(Stack *s);
void clean(Stack *s);

#endif /* DYNAMICSTACK_H */
