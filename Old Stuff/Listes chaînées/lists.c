#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

List newList(void)
{
	List *newList = malloc(sizeof(List));
	
	if (newList == NULL)
		exit(EXIT_FAILURE);

	newList->size = 0;
	newList->first = newList->last = NULL;

	return newList;
}


void InsertBack(List *l, int value)
{
	ListElement *newElement = malloc(sizeof(ListElement));

	if (newElement == NULL)
		exit(EXIT_FAILURE);

	newElement->value = value;
	newElement->next = NULL;

	l->last->next = newElement;
	l->last = newElement;
}

void DeleteBack(List *l)
{
	// Accéder à l'avant dernier élément de la liste pour lui dire que next = NULL
	// Stocker avant dernier et non dernier ?
}

void Clear(List *l)
{
	ListElement *next = l->first->next;

	while (next != NULL)
	{
		
	}
}