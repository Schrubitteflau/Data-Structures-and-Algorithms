#include "list.h"

void Insert(list **l, int val)
{
	list *newElement = malloc(sizeof(list));
	if (!newElement)
		exit(EXIT_FAILURE);

	newElement.value = val;
	newElement.next = NULL;
}