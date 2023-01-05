#include <stdio.h>
#include "cstl.h"

void print(struct queue *queue)
{
    queue = queue->next;
    while (queue) {
        printf ("%d ", *(int*)queue->data);
        queue = queue->next;
    }
    printf("\n");
}

int main(int argc, char ** argv)
{
    struct queue *queue = queue_init();

    int a = 10, b = 20, c = 30, d = 40;

    queue->push(&queue, &a);
    queue->push(&queue, &b);
    queue->push(&queue, &c);
    queue->push(&queue, &d);
    queue->pop(&queue);

    printf("top = %d\n", *(int*) queue->front(&queue));

    print(queue);

    return 0;
}