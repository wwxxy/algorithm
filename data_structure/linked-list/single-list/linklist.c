#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

#define true 1
#define false 0

static ListNode *nodeAlloc()
{
    ListNode *p = malloc(sizeof(ListNode));
    assert(NULL != p);
    return p;
}

ListNode *listInit(ElemType *valarray, int length)
{
    int i;
    ListNode *head, *node, *temp;

    head = nodeAlloc();
    head->val = length;
    temp = head;
    for(i = 0; i < length; i++){
        node = nodeAlloc();
        node->val = valarray[i];
        temp->next = node;
        temp = node;
    }
    temp->next = NULL; //end
    return head;
}

void listDestroy(ListNode *head)
{
    ListNode *p, *temp;
    p = head;
    while(p != NULL && p->next != NULL){
        temp = p->next;
        p->next = temp->next;
        //printf("free %d\n", temp->val);
        free(temp);  //free nodes starting from the head node
    }
}

int listIsEmpty(ListNode *head)
{
    return (head->val == 0);
}

void listInsertPos(ListNode *head, ElemType value, int position)
{
    assert(position >= 1 && position <= head->val + 1);  //param position need to be realistic

    ListNode *p = head;
    while(position > 1){
        p = p->next;
        --position;
    }
    ListNode *new = nodeAlloc();
    new->val = value;
    new->next = p->next;
    p->next = new;

    ++head->val;
}

ElemType listDeletePos(ListNode *head, int position)
{
    assert(position >= 1 && position <= head->val);  //param position need to be realistic

    ListNode *p = head;
    while(position > 1){
        p = p->next;
        --position;
    }

    ElemType data = p->next->val;
    ListNode *temp = p->next;
    p->next = temp->next;
    free(temp);

    --head->val;
    return data;
}

int listDeleteVal(ListNode *head, ElemType value)
{
    ListNode *p = head;
    ListNode *old = head;
    while(old != NULL && (p = old->next) != NULL){
        if(p->val == value){
            ListNode *temp = p;
            old->next = temp->next;
            --head->val;
            free(temp);
            return true;
        }
        old = old->next;
    }
    printf("value was not found in this linked-list\n");
    return false;
}

ListNode *listLocation(ListNode *head, ElemType value)
{
    ListNode *p = head;
    while(p != NULL){
        if(p->val == value){
            return p;
            break;
        }
        p = p->next;
    }
    return NULL;
}

void listDisplay(ListNode *head)
{
    ListNode *p = head->next;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

static ListNode *merge(ListNode *left, ListNode *right)
{
    ListNode *newhead = nodeAlloc();
    ListNode *temp = newhead;

    while(left!=NULL && right != NULL){
        if(left->val <= right->val){ //newhead->left->left....
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    while(left != NULL){
        temp->next = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        right = right->next;
    }

    return newhead->next;
}
static ListNode *listSortRecurse(ListNode *head)
{
    if(head == NULL || head->next == NULL)  return head;

    ListNode *temp, *mid, *right;
    temp = mid = right = head;

    while(right != NULL && right->next != NULL){
        temp = mid; //store node ahead mid;
        mid = mid->next;
        right = right->next->next; //when pointer right arrived the end of the list, mid arrived the middle;
    }
    temp->next = NULL;

    //left half: head->node1...->temp->NULL ;
    //right half: mid->node....->end->NULL;
    return merge(listSortRecurse(head), listSortRecurse(mid));
}
//O(nlogn)
ListNode *listSort(ListNode *head)
{
    head->next = listSortRecurse(head->next);
    return head;
}

ListNode *listReverse(ListNode *head)
{
    if(head->val < 2) return head;

    ListNode *p, *prev, *post;
    p = head->next;
    prev = post = NULL;

    while(p != NULL){
        post = p->next;
        p->next = prev;
        prev = p;
        p = post;
    }

    head->next = prev;
    return head;
}
