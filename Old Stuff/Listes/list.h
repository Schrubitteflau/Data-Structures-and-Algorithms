#ifndef __LIST_H__
#define __LIST_H__

/* Définition du type Booléen */
typedef enum { false, true } Bool;

/* Définition d'une liste */
typedef struct ListElement
{
	int value;
	struct ListElement *next;
} ListElement;

/* Prototypes */
ListElement* new_list(void);
Bool is_list_empty(ListElement *l);
void print_list(ListElement *l);
int list_length(ListElement *l);
ListElement* insert_back(ListElement *l, int val);
ListElement* insert_front(ListElement *l, int val);
void delete_back(ListElement *l);
ListElement* delete_front(ListElement *l);
ListElement* clear(ListElement *l);

#endif //__LIST_H__