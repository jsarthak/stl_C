#include <stdio.h>
#include "cstl.h"

void print(struct stack *stack)
{
    stack = stack->next;
    while (stack) {
        printf ("%d ", *(int*)stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char ** argv)
{
    struct stack *stack = stack_init();

    int a = 10, b = 20, c = 30, d = 40;

    stack->push(&stack, &a);
    stack->push(&stack, &b);
    stack->push(&stack, &c);
    stack->push(&stack, &d);
    stack->pop(&stack);

    printf("top = %d\n", *(int*) stack->top(&stack));

    print(stack);

    return 0;
}