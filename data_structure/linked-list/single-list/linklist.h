#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef int ElemType;

typedef struct ListNode{
    ElemType val;
    struct ListNode *next;
}ListNode;
/** a special case: when ListNode is a header node of this linked-list
 * @val : number of nodes in this linked-list
 * @next: pointing to the first node
 */

//Initialize a linked-list using an array
ListNode *listInit(ElemType *valarray, int length);
//Destroy the list built before
void listDestroy(ListNode *head);
//return true if this linked-list is empty
int listIsEmpty(ListNode *head);
//Display this linked-list
void listDisplay(ListNode *head);

//Insert an value at a specific position which should be less than head->val+1
void listInsertPos(ListNode *head, ElemType value, int position);
//Delete the node at a specific position, return value of the deleted node
ElemType listDeletePos(ListNode *head, int position);
//Delete node by value, return 0 when value is not found in linked-list
int listDeleteVal(ListNode *head, ElemType value);
//Locate by value
ListNode *listLocation(ListNode *head, ElemType value);

//Return sorted linked-list using mergeSort  @https://blog.csdn.net/guaiguaitinghua/article/details/90551871
ListNode *listSort(ListNode *head);
//Return reversed linked-list   @https://www.cnblogs.com/huangxincheng/p/4051854.html
ListNode *listReverse(ListNode *head);
#endif // __LINKLIST_H__
