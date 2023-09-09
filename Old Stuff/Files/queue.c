#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// Création d'une nouvelle file
Queue* new_queue(void)
{
	Queue *new = malloc(sizeof(Queue));

	if (new == NULL)
	{
		fprintf(stderr, "Echec de l'allocation mémoire\n");
		exit(EXIT_FAILURE);
	}

	new->first = new->last = NULL;
	new->queue_size = 0;

	return new;
}

// La file est-elle vide ?
Bool is_queue_empty(Queue *q)
{
	// Logiquement, si first vaut NULL alors last vaut forcément NULL
	if (q->first == NULL && q->last == NULL)
		return true;
	return false;
}

void print_queue(Queue *q)
{
	QueueElement *tmp = q->first;

	if (is_queue_empty(q))
		printf("La file est vide : rien a afficher\n");

	while (tmp != NULL)
	{
		printf("[%d]\n", tmp->value);
		tmp = tmp->next;
	}
}

// Ajouter un élément à la file
void enqueue_queue(Queue *q, int val)
{
	QueueElement *new = malloc(sizeof(QueueElement));
	if (new == NULL)
	{	
		fprintf(stderr, "Erreur d'allocation de mémoire");
		exit(EXIT_FAILURE);
	}

	new->value = val;
	new->next = NULL;

	// Si la file est vide, alors lorsque l'on ajoute un élément il n'y en aura qu'un,
	// celui-ci sera donc ET le premier ET le dernier
	if (is_queue_empty(q))
		q->first = q->last = new;
	else
	{
		// Sinon, l'avant-dernier élément (ancien dernier) voit son pointer next pointer vers le dernier (nouveau dernier)
		q->last->next = new;
		// On modifie donc le pointeur du dernier élément
		q->last = new;
	}

	// La taille de la file augmente de 1
	q->queue_size++;
}


void dequeue_queue(Queue *q)
{
	QueueElement *tmp = q->first;

	if (is_queue_empty(q))
	{
		printf("Rien à retirer, la file est déjà vide");
		return;
	}

	// Noter que l'on va pouvoir modifier le pointeur first sans problème, étant donné que celui-ci a été
	// sauvegardé plus haut

	// Si la file ne contient qu'un seul élément (donc premier = dernier), alors lorsque l'on va le supprimer
	// la file se retrouvera vide : premier = dernier = NULL
	if (q->first == q->last)
		q->first = q->last = NULL;
	else
		q->first = q->first->next;
	// Sinon, si la file contient plus d'un élément, alors on retire le premier élément, et le nouveau premier élément
	// et en fait l'ancien 2ème

	// On peut donc libérer la mémoire de l'ancien premier élément (attention, ici aucun problème avec le free() car on
	// ne manipule que des entiers, si jamais la structure QueueElement avait pour "contenu utile" (c'est-à-dire sans compter
	// le pointeur vers l'élément suivant) un/des pointeurs, il faudrait veiller à gérer leur mémoire en premier temps,
	// une fonction appropriée serait alors necéssaire)
	free(tmp);

	// La taille de la file diminue de 1
	q->queue_size--;
}

// Il vaut se représenter la file en mémoire comme ceci :
/*
	1	->	2	->	3	->	4	-> NULL

Les numéros correspondent à l'ordre d'ajout (enqueue) dans la file : le n°1 est le premier élément ajouté, suivi du n°2, etc.
Lorsque l'on supprime un élément de la file (dequeue), le n°1 est supprimé et le n°2 devient le nouveau n°1 :
	1	->	2	->	3	->	NULL
La logique FIFO : Fist In First Out est bien respectée : premier entré, premier sorti
*/


// Vider la file
void clear_queue(Queue *q)
{
	// Optionnel
	if (is_queue_empty(q))
		printf("Rien a nettoyer : la file est deja vide.\n");

	while (!is_queue_empty(q))
		dequeue_queue(q);
}