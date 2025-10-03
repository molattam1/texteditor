#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

typedef struct {
    char *data;
    int size;
    int top;
} Stack;

int stack_init(Stack *s, int initial_size);
int stack_push(Stack *s, char value);
int stack_pop(Stack *s);
void stack_top_to_bottom(Stack *s1, Stack *s2, int times);
int stack_isEmpty(Stack *s);
void stack_print(Stack *s);
void stack_clean(Stack *s);
char stack_peek(Stack *s);

#endif /* DYNAMICSTACK_H */
