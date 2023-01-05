#include <stdlib.h>
#include "cstl.h"

struct list *list_init(void)
{
	struct list *head = (struct list *)malloc(sizeof(struct list));

	if (!head)
		return NULL;

	head->next = NULL;
	head->push_back = push_back;
	head->push_front = push_front;
	head->push_at = push_at;
	head->pop_at = pop_at;
	head->pop_front = pop_front;
	head->pop_back = pop_back;
	head->front = front;
	head->back = back;
	head->get_at = get_at;
	head->size = list_size;
	
	return head;
}

static int list_size(struct list **head)
{
	struct list *current_head = (*head)->next;
	int len = 0;

	while (current_head)
		len++, current_head = current_head->next;

	return len;
}

static int push_back(struct list **head, void *data)
{
	struct list *new_node = (struct list *)malloc(sizeof(struct list));
	struct list *current_head = (*head)->next;

	new_node->data = data;
	new_node->next = NULL;

	if (current_head == NULL)
	{
		(*head)->next = new_node;
		return 0;
	}

	while (current_head->next)
		current_head = current_head->next;
	current_head->next = new_node;

	return 0;
}

static int push_front(struct list **head, void *data)
{
	struct list *new_node = (struct list *)malloc(sizeof(struct list));
	struct list *current_head = (*head)->next;

	new_node->data = data;
	new_node->next = current_head;
	(*head)->next = new_node;

	return 0;
}

static int push_at(struct list **head, void *data, int position)
{
	struct list *new_node;
	struct list *current_head = (*head)->next;

	if (position == 0)
		return push_front(head, data);

	if (position == list_size(head))
		return push_back(head, data);

	if (position > 0 && position < list_size(head))
	{
		new_node = (struct list *)malloc(sizeof(struct list));
		new_node->data = data;
		new_node->next = NULL;
		while (current_head->next && position--)
			current_head = current_head->next;
		new_node->next = current_head->next;
		current_head->next = new_node;

		return 0;
	}

	return -EINVAL;
}

static int pop_back(struct list **head)
{
	struct list *current_head = (*head)->next;
	struct list *prev = NULL;

	if (!(*head)->next)
		return -EINVAL;

	while (current_head->next)
		prev = current_head, current_head = current_head->next;

	prev->next = NULL;
	free(current_head);

	return 0;
}

static int pop_front(struct list **head)
{
	struct list *current_head = (*head)->next;

	if (!current_head)
		return -EINVAL;

	(*head)->next = current_head->next;
	free(current_head);

	return 0;
}

static int pop_at(struct list **head, int position)
{
	struct list *current_head = (*head)->next;
	struct list *prev = NULL;

	if (position == 0)
		return pop_front(head);

	if (position == (list_size(head) - 1))
		return pop_back(head);

	while (current_head->next && position--)
		prev = current_head, current_head = current_head->next;

	prev->next = current_head->next;
	free(current_head);

	return 0;
}

static void *front(struct list **head)
{
	return (*head)->next->data;
}

static void *back(struct list **head)
{
	struct list *current_head = (*head)->next;

	while (current_head->next)
		current_head = current_head->next;

	return current_head->data;
}

static void *get_at(struct list **head, int position)
{
	struct list *current_head = (*head)->next;

	if (position == 0)
		return front(head);

	if (position == (list_size(head) - 1))
		return back(head);

	if (position > 0 && position < list_size(head))
	{
		while (current_head->next && position--)
			current_head = current_head->next;

		return current_head->data;
	}
	return NULL;
}
