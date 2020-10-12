#include <stdio.h>

#include "singlyLinkedList.h"

#define SIZE_TAB(arr, type) (sizeof(arr) / sizeof(type))
#define SIZE_TAB_INT(arr) SIZE_TAB(arr, int)

struct  ListNode* getTestList1();
struct  ListNode* getTestList2();
struct  ListNode* getTestList3();
void    compareListToArray(struct ListNode *list, int array[], int length, char *testName, int testIndex);
void    testListInsertAtBeginning(struct ListNode **list, int expected[], int expectedLength);
void    testListInsertAtEnding(struct ListNode **list, int expected[], int expectedLength);
void    testListInsertAtPosition(struct ListNode **list, int expected[], int expectedLength);
void    testListDeleteAtBeginning(struct ListNode **list, int expected[], int expectedLength);

int main(void)
{
    struct ListNode *list1, *list2, *list3;
    /* Try each insert/delete function with :
        - NULL
        - 1 element long list
        - 10 elements long list
    */

    // Testing listInsertAtBeginning() function :
    int _1_expected1[] = { 3, 1 },
        _1_expected2[] = { 3, 1, 1 },
        _1_expected3[] = { 3, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list1 = getTestList1(),
    list2 = getTestList2(),
    list3 = getTestList3();

    testListInsertAtBeginning(&list1, _1_expected1, SIZE_TAB(_1_expected1, int));
    testListInsertAtBeginning(&list2, _1_expected2, SIZE_TAB_INT(_1_expected2));
    testListInsertAtBeginning(&list3, _1_expected3, SIZE_TAB_INT(_1_expected3));

    // Testing listInsertAtEnding() function :
    int _2_expected1[] = { 1, 3 },
        _2_expected2[] = { 1, 1, 3 },
        _2_expected3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 3 };
    list1 = getTestList1(),
    list2 = getTestList2(),
    list3 = getTestList3();

    testListInsertAtEnding(&list1, _2_expected1, SIZE_TAB_INT(_2_expected1));
    testListInsertAtEnding(&list2, _2_expected2, SIZE_TAB_INT(_2_expected2));
    testListInsertAtEnding(&list3, _2_expected3, SIZE_TAB_INT(_2_expected3));

    // Testing listInsertAtPosition() function :
    int _3_expected1[] = { 5, 1, 3, 4 },
        _3_expected2[] = { 5, 1, 3, 4, 1 },
        _3_expected3[] = { 5, 1, 3, 4, 1, 2, 3, 4, 5, 2, 6, 7, 8, 9, 10, 5 };
    list1 = getTestList1(),
    list2 = getTestList2(),
    list3 = getTestList3();

    testListInsertAtPosition(&list1, _3_expected1, SIZE_TAB_INT(_3_expected1));
    testListInsertAtPosition(&list2, _3_expected2, SIZE_TAB_INT(_3_expected2));
    testListInsertAtPosition(&list3, _3_expected3, SIZE_TAB_INT(_3_expected3));

    // Testing listDeleteAtBeginning() function :
    int _4_expected1[] = { },
        _4_expected2[] = { },
        _4_expected3[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list1 = getTestList1(),
    list2 = getTestList2(),
    list3 = getTestList3();

    testListDeleteAtBeginning(&list1, _4_expected1, SIZE_TAB_INT(_4_expected1));
    testListDeleteAtBeginning(&list2, _4_expected2, SIZE_TAB_INT(_4_expected2));
    testListDeleteAtBeginning(&list3, _4_expected3, SIZE_TAB_INT(_4_expected3));

    list1 = getTestList2();
    listDeleteAtEnding(&list1);

    return 0;
}

void testListInsertAtBeginning(struct ListNode **list, int expected[], int expectedLength)
{
    static int n = 0;
    static char testName[] = "InsertAtBeginning";

    // Do some stuff to the list...
    listInsertAtBeginning(list, 1);
    listInsertAtBeginning(list, 3);

    // Then compare the list values to the expected list of values
    compareListToArray(*list, expected, expectedLength, testName, n++);
}

void testListInsertAtEnding(struct ListNode **list, int expected[], int expectedLength)
{
    static int n = 0;
    static char testName[] = "InsertAtEnding";

    // Do some stuff to the list...
    listInsertAtEnding(list, 1);
    listInsertAtEnding(list, 3);

    // Then compare the list values to the expected list of values
    compareListToArray(*list, expected, expectedLength, testName, n++);
}

void testListInsertAtPosition(struct ListNode **list, int expected[], int expectedLength)
{
    static int n = 0;
    static char testName[] = "InsertAtPosition";

    // Do some stuff to the list...
    // Warning : indexation begins to 0, so 1 is the second element
    listInsertAtPosition(list, 1, -2);    // First position
    listInsertAtPosition(list, 2, 6);     // After 6th element, so in 7th position
    listInsertAtPosition(list, 3, 1);     // After 1st element, so in 2nd position
    listInsertAtPosition(list, 4, 2);     // After 2nd element, so in 3rd position
    listInsertAtPosition(list, 5, 0);     // First position
    listInsertAtPosition(list, 5, 15);    // After 15th element, so in 16th position

    // With NULL :
    // 5 1 3 4

    // With { 1 } :
    // 5 1 3 4 1

    // With { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } :
    // 5 1 3 4 1 2 3 4 5 2 6 7 8 9 10 5

    // Then compare the list values to the expected list of values
    compareListToArray(*list, expected, expectedLength, testName, n++);
}

void testListDeleteAtBeginning(struct ListNode **list, int expected[], int expectedLength)
{
    static int n = 0;
    static char testName[] = "DeleteAtBeginning";

    // Do some stuff to the list...
    listDeleteAtBeginning(list);

    // Then compare the list values to the expected list of values
    compareListToArray(*list, expected, expectedLength, testName, n++);
}

void compareListToArray(struct ListNode *list, int array[], int length, char *testName, int testIndex)
{
    printf("[%s - %d] : %s\n", testName, testIndex, listCompareToArray(list, array, length) ? "OK" : "Not OK");
}

struct ListNode* getTestList1()
{
    return NULL;
}

struct ListNode* getTestList2()
{
    struct ListNode* ret = NULL;

    listInsertAtBeginning(&ret, 1);

    return ret;
}

struct ListNode* getTestList3()
{
    static int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct ListNode* list = listCreateFromValues(values, 10);

    return list;
}