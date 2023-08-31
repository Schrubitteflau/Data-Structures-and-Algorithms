#include <stdio.h>
#include <stdlib.h>

#include "singlyLinkedList.h"


// Returns an empty list
struct ListNode* listCreateEmpty()
{
    return NULL;
}

// Returns a pointer to the new ListNode, or NULL if malloc() failed
struct ListNode* listCreateNode(int data, struct ListNode *next)
{
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));

    if (ret != NULL)
    {
        ret->data = data;
        ret->next = next;
    }

    return ret;
}

// Returns true if the list is empty, or false
bool listIsEmpty(struct ListNode *list)
{
    // 1 (true) or 0 (false)
    return (list == NULL);
}

// Returns the node at the specified position of the list, or NULL if the position is out of range
struct ListNode* listReachAtPosition(struct ListNode *list, int pos)
{
    // While the position we want is not reached and we are not out of range, travel to the next node
    for (; pos-- != 0 && list != NULL; list = list->next);

    return list;
}

// Returns the last node, or NULL if the list is empty
struct ListNode* listReachLast(struct ListNode *list)
{
    if (listIsEmpty(list))
    {
        return NULL;
    }

    // Travel all the list until we reach the last element
    for (; list->next != NULL; list = list->next);

    return list;
}

// Print the data of the list
// Space Complexity : O(1) for creating 1 local variable
// Time Complexity : O(n) for traversing all the elements of the list
void listPrint(struct ListNode *list)
{
    printf("----------\n");

    for (; list != NULL; list = list->next)
    {
        printf("%d -> ", list->data);
    }

    printf("NULL\nTotal length : %d\n----------\n\n", listLength(list));
}


// Calculate the number of elements in the list
// Space Complexity : O(1) for creating 2 local variables
// Time Complexity : O(n) for traversing all the elements of the list
int listLength(struct ListNode *list)
{
    int size = 0;

    for (; list != NULL; list = list->next)
    {
        size++;
    }

    return size;
}


// Insert an element at the beginning of the list
// Space Complexity : O(1) for creating 1 variable and allocating constant amount of memory
// Time Complexity : O(1)
bool listInsertAtBeginning(struct ListNode **list, int data)
{
    struct ListNode* element = listCreateNode(data, *list);

    if (element == NULL)
    {
        return false;
    }

    *list = element;

    return true;
}


// Insert an element at the ending of the list
// Space Complexity : O(1)
// Time Complexity : O(n) because travelling all the list
bool listInsertAtEnding(struct ListNode **list, int data)
{
    // We already know that element->next will be NULL, because it will be the last element
    struct ListNode* element = listCreateNode(data, NULL);
    struct ListNode* temp;

    if (element == NULL)
    {
        return false;
    }

    // Travel all the list until we reach the last element
    temp = listReachLast(*list);

    // If NULL is returned, then the list is empty, so the new element become the list
    if (temp == NULL)
    {
        *list = element;
        return true;
    }

    // temp contain the current last element because temp->next is equal to NULL
    temp->next = element;

    return true;
}

// Insert an element at given position pos
// Warning : indexation begins to 0, so 1 is the second position (like classic arrays)
// Space complexity : O(1)
// Time complexity : O(n) because travelling all the list in the worst case
bool listInsertAtPosition(struct ListNode **list, int data, int pos)
{
    struct ListNode *element;
    struct ListNode *temp;

    // If pos < 1, then insert at the beginning
    if (pos < 1)
    {
        element = listCreateNode(data, *list);
        if (element == NULL)
        {
            return false;
        }

        *list = element;
        return true;
    }

    // Travel all the list until we reach pos - 1 element
    temp = listReachAtPosition(*list, pos - 1);

    // pos is too far
    if (temp == NULL)
    {
        return false;
    }

    element = listCreateNode(data, temp->next);
    if (element == NULL)
    {
        return false;
    }

    // Now temp is the pos - 1 element, so we can change it's next pointer
    temp->next = element;
    
    return true;
}

// Return a new list filled with values
struct ListNode* listCreateFromValues(int values[], int length)
{
    struct ListNode *list = listCreateEmpty();

    // Loop over values and insert them as node : we start from the end of the array to call
    // listInsertAtBeginning() which is O(1) instead of listInsertAtEnding() which is O(n)
    while (length--)
    {
        if (!listInsertAtBeginning(&list, values[length]))
        {
            // Should never happen
            fprintf(stderr, "Error while inserting at ending... deleting list");
            listDelete(&list);
            return NULL;
        }
    }

    return list;
}

// Compare list values to values of the given array
bool listCompareToArray(struct ListNode *list, int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (listIsEmpty(list) || list->data != array[i])
        {
            return false;
        }
        list = list->next;
    }

    return true;
}

// Delete the first node of the list
// Space complexity : O(1)
// Time complexity : O(1)
bool listDeleteAtBeginning(struct ListNode **list)
{
    struct ListNode *toRemove;

    if (listIsEmpty(*list))
    {
        return false;
    }

    // Store the actual first node
    toRemove = *list;
    // Set the first node of the list to the previous second node
    *list = (*list)->next;
    // Now, free the memory of the previous first node
    free(toRemove);

    return true;
}

// Delete the last element of the list
// Space complexity : O(1)
// Time complexity : O(n)
bool listDeleteAtEnding(struct ListNode **list)
{
    struct ListNode *temp;

    // Don't do anything
    if (listIsEmpty(*list))
    {
        return false;
    }

    // If the list is 1 element length
    if ((*list)->next == NULL)
    {
        // Then free the element
        free((*list)->next);
        // And set the list point to NULL
        *list = NULL;

        return true;
    }

    // Reach the before last element
    for (temp = *list; temp->next->next != NULL; temp = temp->next);

    // Then free the memory of the last
    free(temp->next);
    // And set the pointer to NULL
    temp->next = NULL;
    
    return true;
}

// Delete an element of the list at the given position
// Space complexity : O(1)
// Time complexity : O(n), time to reach the node
bool listDeleteAtPosition(struct ListNode **list, int pos)
{
    struct ListNode *temp, *toFree;

    // If the list is empty, or if the position is < 0, then don't do anything
    if (listIsEmpty(*list) || pos < 0)
    {
        return false;
    }

    // We want to reach the pos - 1 node to change it's next pointer
    temp = listReachAtPosition(*list, pos - 1);
    // If pos - 1 is out of range or if pos - 1 is in range but not pos (that we want do delete), dont't do anything
    if (temp == NULL || temp->next == NULL)
    {
        return false;
    }

    // We want to free the memory of temp->next and make temp points to actual temp->next->next (maybe NULL, we don't care)
    toFree = temp->next;
    temp->next = toFree->next;
    free(toFree);

    return true;
}

// Delete the whole list
// Space complexity : O(1)
// Time complexity : O(n) for scanning the complete list of size n
void listDelete(struct ListNode **list)
{
    struct ListNode *current, *temp;

    for (current = *list; current != NULL;)
    {
        // Before deleting a node, we need to save the next pointer
        temp = current->next;
        free(current);
        current = temp;
    }

    *list = NULL;
}