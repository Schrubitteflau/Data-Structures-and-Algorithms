#include <stdio.h>
#include <stdlib.h>

#include "list.h"

ListElement* new_list(void)
{
	return NULL;
}

/*------------------------------------*/

Bool is_list_empty(ListElement *l)
{
	if (l == NULL)
		return true;

	return false;
}

/*------------------------------------*/

void print_list(ListElement *l)
{
	if (is_list_empty(l))
		printf("Rien a afficher, la liste est vide\n");

	while (l != NULL)
	{
		printf("[%d] -> ", l->value);
		l = l->next;
	}

	putchar('\n');
}

/*------------------------------------*/

int list_length(ListElement *l)
{
	int size = 0;

	// On ne modifie pas réellement l, car c'est une copie
	while (l != NULL)
	{
		l = l->next;
		size++;
	}

	return size;
}

/*------------------------------------*/

ListElement* insert_back(ListElement *l, int val)
{
	ListElement *tmp, *new = malloc(sizeof(ListElement));
	if (new == NULL)
	{
		fprintf(stderr, "Erreur allocation dynamique\n");
		exit(EXIT_FAILURE);
	}

	new->value = val;
	new->next = NULL;

	if (is_list_empty(l))
		return new;

	tmp = l;

	// On parcours toute la liste pour que tmp pointe
	// sur le dernier élément de la liste
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new;

	return l;
}

/*------------------------------------*/

ListElement* insert_front(ListElement *l, int val)
{
	ListElement *new = malloc(sizeof(ListElement));
	if (new == NULL)
	{
		fprintf(stderr, "Erreur allocation dynamique\n");
		exit(EXIT_FAILURE);
	}

	new->value = val;
	new->next = l;

	return new;
}

/*------------------------------------*/

void delete_back(ListElement *l)
{
	ListElement *before;

	if (is_list_empty(l))
		return;

	// Si la liste ne contient qu'un seul élément
	if (l->next == NULL)
	{
		free(l);
	}

	// On déplace le pointeur l jusqu'au dernier élément
	// de la liste, et before jusqu'à l'avant dernier
	while(l->next != NULL)
	{
		before = l;
		l = l->next;
	}

	before->next = NULL;

	free(l);
}

/*------------------------------------*/

ListElement* delete_front(ListElement *l)
{
	ListElement *new_first = NULL;

	if (!is_list_empty(l))
	{
		new_first = l->next;
		free(l);
	}

	return new_first;
}

/*------------------------------------*/

ListElement* clear(ListElement *l)
{
	while (l != NULL)
		l = delete_front(l);

	return NULL;
}