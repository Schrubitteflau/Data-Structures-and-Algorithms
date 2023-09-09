#ifndef __LISTS_H__
#define __LISTS_H__

// Objectif à terme : bibliothèque compilée qui permet de faire des listes de toutes sortes
// d'éléments (pointeur void*)

typedef enum { false, true } bool;

struct ListElement
{
	int value;
	struct ListElement *next;
}

typedef struct List
{
	int size;
	struct ListElement *first;
	struct ListElement *last;
} List;

#endif //__LISTS_H__