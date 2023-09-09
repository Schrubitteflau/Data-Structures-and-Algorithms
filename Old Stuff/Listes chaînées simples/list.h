#if !defined __LIST_H__
#define __LIST_H__

typedef struct list
{
	int value;
	struct list *next;

} list;

void Insert(list **l, int val);

#endif //__LIST_H__