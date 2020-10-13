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

// Returns TRUE if the list is empty, or FALSE
bool_t listIsEmpty(struct ListNode *list)
{
    // 1 (TRUE) or 0 (FALSE)
    return (list == NULL);
}

// Print the data of the list
// Space Complexity : O(1) for creating 1 local variable
// Time Complexity : O(n) for traversing all the elements of the list
void listPrint(struct ListNode *list)
{
    struct ListNode *current;

    printf("----------\n");

    for (current = list; current != NULL; current = current->next)
    {
        printf("%d -> ", current->data);
    }

    printf("NULL\nTotal length : %d\n----------\n\n", listLength(list));
}


// Calculate the number of elements in the list
// Space Complexity : O(1) for creating 2 local variables
// Time Complexity : O(n) for traversing all the elements of the list
int listLength(struct ListNode *list)
{
    struct ListNode *current;
    int size = 0;

    for (current = list; current != NULL; current = current->next)
    {
        size++;
    }

    return size;
}


// Insert an element at the beginning of the list
// Space Complexity : O(1) for creating 1 variable and allocating constant amount of memory
// Time Complexity : O(1)
bool_t listInsertAtBeginning(struct ListNode **list, int data)
{
    struct ListNode* element = listCreateNode(data, *list);

    if (element == NULL)
    {
        return FALSE;
    }

    *list = element;

    return TRUE;
}


// Insert an element at the ending of the list
// Space Complexity : O(1)
// Time Complexity : O(n) because travelling all the list
bool_t listInsertAtEnding(struct ListNode **list, int data)
{
    // We already know that element->next will be NULL, because it will be the last element
    struct ListNode* element = listCreateNode(data, NULL);
    struct ListNode* temp;

    if (element == NULL)
    {
        return FALSE;
    }

    // If the list is empty, then the new element become the list
    if (listIsEmpty(*list))
    {
        *list = element;
        return TRUE;
    }

    // Travel all the list until we reach the last element
    for (temp = *list; temp->next != NULL; temp = temp->next);

    // temp contain the current last element because temp->next is equal to NULL
    temp->next = element;

    return TRUE;
}

// Insert an element at given position pos
// Warning : indexation begins to 0, so 1 is the second position (like classic arrays)
// Space complexity : O(1)
// Time complexity : O(n) because travelling all the list in the worst case
bool_t listInsertAtPosition(struct ListNode **list, int data, int pos)
{
    struct ListNode *element;
    struct ListNode *temp;

    // If pos < 1, then insert at the beginning
    if (pos < 1)
    {
        element = listCreateNode(data, *list);
        if (element == NULL)
        {
            return FALSE;
        }

        *list = element;
        return TRUE;
    }

    // Travel all the list until we reach pos - 1 element

    // Loop while we haven't reach the pos - 1 element : when pos == 0, we looped pos times, and we
    // want to loop pos - 1 times so we check that pos never reach the value 0
    // We also check that we didn't reach the end of the list before reaching the wanted position

    // Decrement pos before the condition because if pos value is 2 (for example), we want to stop at the first element,
    // so only one iteration.
    for (temp = *list; --pos && temp != NULL; temp = temp->next);

    // pos is too far
    if (temp == NULL)
    {
        return FALSE;
    }

    element = listCreateNode(data, temp->next);
    if (element == NULL)
    {
        return FALSE;
    }

    // Now temp is the pos - 1 element, so we can change it's next pointer
    temp->next = element;
    
    return TRUE;
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
            listDelete(list);
            return NULL;
        }
    }

    return list;
}

// Compare list values to values of the given array
bool_t listCompareToArray(struct ListNode *list, int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (listIsEmpty(list) || list->data != array[i])
        {
            return FALSE;
        }
        list = list->next;
    }

    return TRUE;
}

// Delete the first node of the list
// Space complexity : O(1)
// Time complexity : O(1)
bool_t listDeleteAtBeginning(struct ListNode **list)
{
    struct ListNode *toRemove;

    if (listIsEmpty(*list))
    {
        return FALSE;
    }

    // Store the actual first node
    toRemove = *list;
    // Set the first node of the list to the previous second node
    *list = (*list)->next;
    // Now, free the memory of the previous first node
    free(toRemove);

    return TRUE;
}

// Delete the last element of the list
// Space complexity : O(1)
// Time complexity : O(n)
bool_t listDeleteAtEnding(struct ListNode **list)
{
    struct ListNode *temp;

    // Don't do anything
    if (listIsEmpty(*list))
    {
        return FALSE;
    }

    // If the list is 1 element length
    if ((*list)->next == NULL)
    {
        // Then free the element
        free((*list)->next);
        // And set the list point to NULL
        *list = NULL;

        return TRUE;
    }

    // Reach the before last element
    for (temp = *list; temp->next->next != NULL; temp = temp->next);

    // Then free the memory of the last
    free(temp->next);
    // And set the pointer to NULL
    temp->next = NULL;
    
    return TRUE;
}

bool_t listDelete(struct ListNode *list)
{

}