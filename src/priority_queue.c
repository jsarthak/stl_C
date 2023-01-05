#include <stdlib.h>
#include "cstl.h"

struct priority_queue *priority_queue_init(int flag)
{
    struct priority_queue *queue_head = malloc(sizeof(struct priority_queue));
    queue_head->flag = flag;
    queue_head->data = NULL;
    queue_head->left = NULL;
    queue_head->right = NULL;

    return queue_head;
}

static int priority_queue_push(struct priority_queue **pq, void *data)
{
    return 0;

}
static void *priority_queue_pop(struct priority_queue **pq)
{
    return pq->left->data;
}
static void *priority_queue_top(struct priority_queue **pq)
{
    return pq->left->data;
}
static int priority_queue_empty(struct priority_queue **pq)
{
    return pq->left == NULL ? 1 : 0;
}
static int priority_queue_size(struct priority_queue **pq)
{
    
}