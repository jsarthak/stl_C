#include <stdio.h>
#include "cstl.h"

void print(struct list *head)
{
	head = head->next;
	while (head)
	{
		printf("%d ", *(int *)head->data);
		head = head->next;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	struct list *list = list_init();
	int a = 0, b = 1, c = 3, d = 4;

	list->push_back(&list, &a);
	list->push_back(&list, &b);
	list->push_front(&list, &c);

	print(list);
	

	return 0;
}
