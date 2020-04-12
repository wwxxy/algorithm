#include <stdio.h>
#include "linklist.h"

int main(void)
{
    //ElemType arr[] = {1, 2, 3, 5, 6};
    ElemType arr[] = {2, 5, 1, 6, 3};
    ListNode *head = NULL;

    head = listInit(arr, sizeof(arr)/sizeof(ElemType));
    //printf("size : %d\n", head->val);
    listInsertPos(head, 4, 4);
    listDisplay(head);
    printf("size : %d\n", head->val);
    //ElemType x = listDelete(head, 6);
    //printf("after delete %d, size : %d\n", x, head->val);
    //ListNode *index = listLocation(head, 4);
    //listDeleteVal(head, 5);
    head = listSort(head);
    listDisplay(head);
    head = listReverse(head);
    listDisplay(head);
    printf("size : %d\n", head->val);
    listDestroy(head);

    return 0;
}
