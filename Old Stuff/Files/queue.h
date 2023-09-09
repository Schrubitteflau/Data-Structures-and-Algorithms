#ifndef __QUEUE_H__
#define __QUEUE_H__

// Lorsque l'on appelle la macro queue_length(myQueue), ceci est remplacé par myQueue->queue_size par exemple
// C'est un peu l'équivalent des fonctions inline (C++), car ça ne sert à rien de créer des fonctions qui ne font
// que retourner une valeur : plus de code pour pas grand chose
#define queue_length(q) q->queue_size
#define queue_first(q)  q->first
#define queue_last(q)   q->last

/* Définition du type Booléen */
typedef enum { false, true } Bool;

/* Définition d'une File */
typedef struct QueueElement
{
	int value;
	struct QueueElement *next;
} QueueElement;

typedef struct Queue
{
	QueueElement *first, *last;
	int queue_size;
} Queue;

/* Prototypes */
Queue* new_queue(void);
Bool is_queue_empty(Queue *q);
void print_queue(Queue *q);
void enqueue_queue(Queue *q, int val);
void dequeue_queue(Queue *q);
void clear_queue(Queue *q);

#endif //__QUEUE_H__