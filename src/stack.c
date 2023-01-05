#include "cstl.h"
#include <stdlib.h>

struct stack *stack_init(void)
{
    struct stack *stack_head = (struct stack *) malloc(sizeof(struct stack));

    stack_head->next = NULL;
    stack_head->push = stack_push;
    stack_head->pop = stack_pop;
    stack_head->top = stack_top;
    stack_head->is_empty = stack_empty;
    stack_head->size =  stack_size;

    return stack_head;
}

static int stack_push(struct stack **stack, void *data)
{
    struct stack *new_node = (struct stack *)malloc(sizeof(struct stack));
	struct stack *current_head;

	new_node->data = data;
    new_node->next = (*stack)->next;
    (*stack)->next = new_node;

	return 0;
}

static void* stack_pop(struct stack **stack)
{
    struct stack *current = (*stack)->next;

    if (!current)
        return NULL;

    (*stack)->next = current->next;
    void *data = current->data;
    free(current);
    return data;
}

static void* stack_top(struct stack **stack)
{
    struct stack *current = (*stack)->next;

    if (!current)
        return NULL;

    return current->data;
}

static int stack_empty(struct stack **stack)
{
    if (!(*stack)->next)
        return 1;
    return 0;
}

static int stack_size(struct stack **stack)
{
    int len = 0;
    struct stack *current = (*stack)->next;

    while (current)
        len++, current = current->next;

    return len;
}