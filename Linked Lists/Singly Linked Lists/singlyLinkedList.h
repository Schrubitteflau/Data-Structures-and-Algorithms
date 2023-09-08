#ifndef __SINGLY_LINKED_LIST_H__

#define __SINGLY_LINKED_LIST_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CreateListNodeType(type) \
/* List element */ \
struct ListNode_##type \
{ \
    /* Current data to store */ \
    type data; \
    /* Next element of the list */ \
    struct ListNode_##type* next; \
}; \

#define CreateListNodeDeclaration(type) \
struct ListNode_##type*     listCreateNode_##type (type data, struct ListNode_##type *next); \
struct ListNode_##type*     listCreateEmpty_##type (); \
bool                        listIsEmpty_##type ( struct ListNode_##type *list); \
struct ListNode_##type*     listReachAtPosition_##type ( struct ListNode_##type *list, int pos); \
struct ListNode_##type*     listReachLast_##type ( struct ListNode_##type *list); \
void                        listPrint_##type ( struct ListNode_##type *list); \
int                         listLength_##type ( struct ListNode_##type *list); \
bool                        listInsertAtBeginning_##type ( struct ListNode_##type **list, type data); \
bool                        listInsertAtEnding_##type ( struct ListNode_##type **list, type data); \
bool                        listInsertAtPosition_##type ( struct ListNode_##type **list, type data, int pos); \
struct ListNode_##type*     listCreateFromValues_##type ( type values[], int length); \
bool                        listCompareToArray_##type ( struct ListNode_##type *list, type array[], int length); \
bool                        listDeleteAtBeginning_##type ( struct ListNode_##type **list); \
bool                        listDeleteAtEnding_##type ( struct ListNode_##type **list); \
bool                        listDeleteAtPosition_##type ( struct ListNode_##type **list, int pos); \
void                        listDelete_##type ( struct ListNode_##type **list); \

#define CreateListNodeImplementation(type) \
/* Returns an empty list */ \
struct ListNode_##type* listCreateEmpty_##type() \
{ \
    return NULL; \
} \
\
/* Returns a pointer to the new ListNode, or NULL if malloc() failed */ \
struct ListNode_##type* listCreateNode_##type(type data, struct ListNode_##type *next) \
{ \
    struct ListNode_##type *ret = (struct ListNode_##type*)malloc(sizeof(struct ListNode_##type)); \
\
    if (ret != NULL) \
    { \
        ret->data = data; \
        ret->next = next; \
    } \
\
    return ret; \
} \
\
/* Returns true if the list is empty, or false */ \
bool listIsEmpty_##type(struct ListNode_##type *list)\
{\
    /* 1 (true) or 0 (false) */\
    return (list == NULL);\
}\
\
/* Returns the node at the specified position of the list, or NULL if the position is out of range */\
struct ListNode_##type* listReachAtPosition_##type(struct ListNode_##type *list, int pos)\
{\
    /* While the position we want is not reached and we are not out of range, travel to the next node */\
    for (; pos-- != 0 && list != NULL; list = list->next);\
\
    return list;\
}\
\
/* Returns the last node, or NULL if the list is empty */\
struct ListNode_##type* listReachLast_##type(struct ListNode_##type *list)\
{\
    if (listIsEmpty_##type(list))\
    {\
        return NULL;\
    }\
\
    /* Travel all the list until we reach the last element */\
    for (; list->next != NULL; list = list->next);\
\
    return list;\
}\
\
/* Print the data of the list */\
/* Space Complexity : O(1) for creating 1 local variable */\
/* Time Complexity : O(n) for traversing all the elements of the list */\
void listPrint_##type(struct ListNode_##type *list) \
{\
    printf("----------\n");\
\
    for (; list != NULL; list = list->next)\
    {\
        printf("%d -> ", list->data);\
    }\
\
    printf("NULL\nTotal length : %d\n----------\n\n", listLength_##type(list));\
}\
\
\
/* Calculate the number of elements in the list */\
/* Space Complexity : O(1) for creating 2 local variables */\
/* Time Complexity : O(n) for traversing all the elements of the list */\
int listLength_##type(struct ListNode_##type *list)\
{\
    int size = 0;\
\
    for (; list != NULL; list = list->next)\
    {\
        size++;\
    }\
\
    return size;\
}\
\
\
/* Insert an element at the beginning of the list */\
/* Space Complexity : O(1) for creating 1 variable and allocating constant amount of memory */\
/* Time Complexity : O(1) */\
bool listInsertAtBeginning_##type(struct ListNode_##type **list, type data)\
{ \
    struct ListNode_##type* element = listCreateNode_##type(data, *list);\
\
    if (element == NULL)\
    { \
        return false;\
    } \
\
    *list = element;\
\
    return true;\
} \
\
\
/* Insert an element at the ending of the list */\
/* Space Complexity : O(1) */\
/* Time Complexity : O(n) because travelling all the list */\
bool listInsertAtEnding_##type(struct ListNode_##type **list, type data)\
{\
    /* We already know that element->next will be NULL, because it will be the last element */\
    struct ListNode_##type* element = listCreateNode_##type(data, NULL);\
    struct ListNode_##type* temp;\
\
    if (element == NULL)\
    {\
        return false;\
    }\
\
    /* Travel all the list until we reach the last element */\
    temp = listReachLast_##type(*list);\
\
    /* If NULL is returned, then the list is empty, so the new element become the list */\
    if (temp == NULL)\
    {\
        *list = element;\
        return true;\
    }\
\
    /* temp contain the current last element because temp->next is equal to NULL */\
    temp->next = element;\
\
    return true;\
}\
\
/* Insert an element at given position pos */\
/* Warning : indexation begins to 0, so 1 is the second position (like classic arrays) */\
/* Space complexity : O(1) */\
/* Time complexity : O(n) because travelling all the list in the worst case */\
bool listInsertAtPosition_##type(struct ListNode_##type **list, type data, int pos)\
{\
    struct ListNode_##type *element;\
    struct ListNode_##type *temp;\
\
    /* If pos < 1, then insert at the beginning */\
    if (pos < 1)\
    {\
        element = listCreateNode_##type(data, *list);\
        if (element == NULL)\
        {\
            return false;\
        }\
\
        *list = element;\
        return true;\
    }\
\
    /* Travel all the list until we reach pos - 1 element */\
    temp = listReachAtPosition_##type(*list, pos - 1);\
\
    /* pos is too far */\
    if (temp == NULL)\
    {\
        return false;\
    }\
\
    element = listCreateNode_##type(data, temp->next);\
    if (element == NULL)\
    {\
        return false;\
    }\
\
    /* Now temp is the pos - 1 element, so we can change it's next pointer */\
    temp->next = element;\
    \
    return true;\
}\
\
/* Return a new list filled with values */\
struct ListNode_##type* listCreateFromValues_##type(type values[], int length)\
{\
    struct ListNode_##type *list = listCreateEmpty_##type();\
\
    /* Loop over values and insert them as node : we start from the end of the array to call */\
    /* listInsertAtBeginning() which is O(1) instead of listInsertAtEnding() which is O(n) */\
    while (length--)\
    {\
        if (!listInsertAtBeginning_##type(&list, values[length]))\
        {\
            /* Should never happen */\
            fprintf(stderr, "Error while inserting at ending... deleting list");\
            listDelete_##type(&list);\
            return NULL;\
        }\
    }\
\
    return list;\
}\
\
/* Compare list values to values of the given array */\
bool listCompareToArray_##type(struct ListNode_##type *list, type array[], int length)\
{\
    for (int i = 0; i < length; i++)\
    {\
        if (listIsEmpty_##type(list) || list->data != array[i])\
        {\
            return false;\
        }\
        list = list->next;\
    }\
\
    return true;\
}\
\
/* Delete the first node of the list */\
/* Space complexity : O(1) */\
/* Time complexity : O(1) */\
bool listDeleteAtBeginning_##type(struct ListNode_##type **list)\
{\
    struct ListNode_##type *toRemove;\
\
    if (listIsEmpty_##type(*list))\
    {\
        return false;\
    }\
\
    /* Store the actual first node */\
    toRemove = *list;\
    /* Set the first node of the list to the previous second node */\
    *list = (*list)->next;\
    /* Now, free the memory of the previous first node */\
    free(toRemove);\
\
    return true;\
}\
\
/* Delete the last element of the list */\
/* Space complexity : O(1) */\
/* Time complexity : O(n) */\
bool listDeleteAtEnding_##type(struct ListNode_##type **list)\
{\
    struct ListNode_##type *temp;\
\
    /* Don't do anything */\
    if (listIsEmpty_##type(*list))\
    {\
        return false;\
    }\
\
    /* If the list is 1 element length */\
    if ((*list)->next == NULL)\
    {\
        /* Then free the element */\
        free((*list)->next);\
        /* And set the list point to NULL */\
        *list = NULL;\
\
        return true;\
    }\
\
    /* Reach the before last element */\
    for (temp = *list; temp->next->next != NULL; temp = temp->next);\
\
    /* Then free the memory of the last */\
    free(temp->next);\
    /* And set the pointer to NULL */\
    temp->next = NULL;\
    \
    return true;\
}\
\
/* Delete an element of the list at the given position */\
/* Space complexity : O(1) */\
/* Time complexity : O(n), time to reach the node */\
bool listDeleteAtPosition_##type(struct ListNode_##type **list, int pos)\
{\
    struct ListNode_##type *temp, *toFree;\
\
    /* If the list is empty, or if the position is < 0, then don't do anything */\
    if (listIsEmpty_##type(*list) || pos < 0)\
    {\
        return false;\
    }\
\
    /* We want to reach the pos - 1 node to change it's next pointer */\
    temp = listReachAtPosition_##type(*list, pos - 1);\
    /* If pos - 1 is out of range or if pos - 1 is in range but not pos (that we want do delete), dont't do anything */\
    if (temp == NULL || temp->next == NULL)\
    {\
        return false;\
    }\
\
    /* We want to free the memory of temp->next and make temp points to actual temp->next->next (maybe NULL, we don't care) */\
    toFree = temp->next;\
    temp->next = toFree->next;\
    free(toFree);\
\
    return true;\
}\
\
/* Delete the whole list */\
/* Space complexity : O(1) */\
/* Time complexity : O(n) for scanning the complete list of size n */\
void listDelete_##type(struct ListNode_##type **list)\
{\
    struct ListNode_##type *current, *temp;\
\
    for (current = *list; current != NULL;)\
    {\
        /* Before deleting a node, we need to save the next pointer */\
        temp = current->next;\
        free(current);\
        current = temp;\
    }\
\
    *list = NULL;\
}\

#endif