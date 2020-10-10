#ifndef __SINGLY_LINKED_LIST_H__

#define __SINGLY_LINKED_LIST_H__

typedef enum bool_t { FALSE, TRUE } bool_t;

// List element
struct ListNode
{
    // Current data to store
    int data;
    // Next element of the list
    struct ListNode* next;
};

void                listPrint(struct ListNode *list);
int                 listLength(struct ListNode *list);
bool_t              listInsertAtBeginning(struct ListNode **list, int data);
bool_t              listInsertAtEnding(struct ListNode **list, int data);
bool_t              listInsertAtPosition(struct ListNode **list, int data, int pos);
struct ListNode*    listCreateFromValues(int values[], int length);
void                listDelete(struct ListNode *list);
bool_t              listCompareToArray(struct ListNode *list, int array[], int length);

#endif