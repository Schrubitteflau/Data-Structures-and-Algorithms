#ifndef __SINGLY_LINKED_LIST_H__

#define __SINGLY_LINKED_LIST_H__

#include <stdbool.h>
//typedef enum bool_t { FALSE, TRUE } bool_t;

// List element
struct ListNode
{
    // Current data to store
    int data;
    // Next element of the list
    struct ListNode* next;
};

struct ListNode*    listCreateNode(int data, struct ListNode *next);
struct ListNode*    listCreateEmpty();
bool                listIsEmpty(struct ListNode *list);
struct ListNode*    listReachAtPosition(struct ListNode *list, int pos);
struct ListNode*    listReachLast(struct ListNode *list);
void                listPrint(struct ListNode *list);
int                 listLength(struct ListNode *list);
bool                listInsertAtBeginning(struct ListNode **list, int data);
bool                listInsertAtEnding(struct ListNode **list, int data);
bool                listInsertAtPosition(struct ListNode **list, int data, int pos);
struct ListNode*    listCreateFromValues(int values[], int length);
bool                listCompareToArray(struct ListNode *list, int array[], int length);
bool                listDeleteAtBeginning(struct ListNode **list);
bool                listDeleteAtEnding(struct ListNode **list);
bool                listDeleteAtPosition(struct ListNode **list, int pos);
void                listDelete(struct ListNode **list);

#endif