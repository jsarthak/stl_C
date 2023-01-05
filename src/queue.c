#include <stdlib.h>
#include "cstl.h"

struct queue *queue_init(void)
{
    struct queue *queue_head = (struct queue *) malloc(sizeof(struct queue));

    queue_head->next = NULL;
    queue_head->push = queue_push;
    queue_head->pop = queue_pop;
    queue_head->front = queue_front;
    queue_head->is_empty = queue_empty;
    queue_head->size =  queue_size;

    return queue_head;
}

static int queue_push(struct queue **queue, void *data)
{
    struct queue *new_node = (struct queue *)malloc(sizeof(struct queue));
	struct queue *current_head;

    new_node->data = data;
    new_node->next = NULL;

	if (!(*queue)->next) {
        (*queue)->next = new_node;
        return 0;
    }

    current_head = (*queue)->next;
    while (current_head->next)
        current_head = current_head->next;
    
    current_head->next = new_node;

	return 0;
}

static void* queue_pop(struct queue **queue)
{
    struct queue *current = (*queue)->next;

    if (!current)
        return NULL;

    (*queue)->next = current->next;
    void *data = current->data;
    free(current);
    return data;
}

static void* queue_front(struct queue **queue)
{
    struct queue *current = (*queue)->next;

    if (!current)
        return NULL;

    return current->data;
}

static int queue_empty(struct queue **queue)
{
    if (!(*queue)->next)
        return 1;
    return 0;
}

static int queue_size(struct queue **queue)
{
    int len = 0;
    struct queue *current = (*queue)->next;

    while (current)
        len++, current = current->next;

    return len;
}