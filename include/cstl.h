#ifndef __CSTL_H__
#define __CSTL_H__

#include "errno.h"

#define ASCENDING 0
#define DESCENDING 1

/* List structure*/
struct list {
	void *data;
	struct list *next;
	int (*push_back)(struct list **, void *);
	int (*push_front)(struct list **, void *);
	int (*push_at)(struct list **, void *, int);
	int (*pop_back)(struct list **);
	int (*pop_front)(struct list **);
	int (*pop_at)(struct list **, int);
	void* (*front)(struct list **);
	void* (*back)(struct list **);
	void* (*get_at)(struct list **, int);
	int (*size)(struct list **);
};

struct list *list_init(void);
static int list_size(struct list **);
static int push_back(struct list **head, void *data);
static int push_front(struct list **head, void *data);
static int push_at(struct list **head, void *data, int position);
static int pop_back(struct list **head);
static int pop_front(struct list **head);
static int pop_at(struct list **head, int position);
static void *front(struct list **head);
static void *back(struct list **head);
static void *get_at(struct list **head, int position);


/* Stack */
struct stack {
	void *data;
	struct stack *next;
	int (*push)(struct stack **, void *);
	void* (*pop)(struct stack **);
	void* (*top)(struct stack **);
	int (*is_empty)(struct stack**);
	int (*size)(struct stack**);
};

struct stack *stack_init(void);
static int stack_push(struct stack **, void *);
static void* stack_pop(struct stack **);
static void* stack_top(struct stack **);
static int stack_empty(struct stack **);
static int stack_size(struct stack **);

/* Queue*/
struct queue {
	void *data;
	struct queue *next;
	int (*push)(struct queue **, void *);
	void* (*pop)(struct queue **);
	void* (*front)(struct queue **);
	int (*is_empty)(struct queue**);
	int (*size)(struct queue**);
};

struct queue *queue_init(void);
static int queue_push(struct queue **, void *);
static void* queue_pop(struct queue **);
static void* queue_front(struct queue **);
static int queue_empty(struct queue **);
static int queue_size(struct queue **);

struct priority_queue {
    void *data;
    struct priority_queue *left;
    struct priority_queue *right;
    int flag;
    int (*push)(struct priority_queue **, void *);
    void* (*pop)(struct priority_queue **);
    void* (*top)(struct priority_queue **);
    int (*is_empty)(struct priority_queue **);
    int (*size)(struct priority_queue **);
};


struct priority_queue *priority_queue_init(int flag);
static int priority_queue_push(struct priority_queue **, void *);
static void *priority_queue_pop(struct priority_queue **);
static void *priority_queue_top(struct priority_queue **);
static int priority_queue_empty(struct priority_queue **);
static int priority_queue_size(struct priority_queue **);
#endif