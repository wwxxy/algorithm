#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 32
#define RECURSE

typedef struct node{
    int data;
    struct node *lchild, *rchild;
}BiTree;

#ifndef RECURSE
void preBiTree(const BiTree *t)
{
    BiTree *temp = t;
    BiTree *stack[STACK_SIZE] = {NULL};
    int top = -1;

    while(temp != NULL || top != -1){  //当且仅有当前节点为空且栈为空时，结束
        //当前节点存在，存入栈中，并访问左子树；
        if(temp != NULL){   //节点非空，两种情况，空栈或非空栈
            printf("%d ", temp->data);
            stack[++top] = temp;
            temp = temp->lchild;
        }else{ //节点为空，栈非空
            //当前节点不存在，就出栈，并通过栈顶节点访问右子树
            temp = stack[top--];
            temp = temp->rchild;
        }
    }
}


void inBiTree(const BiTree *t)
{
    BiTree *temp = t;
    BiTree *stack[STACK_SIZE] = {NULL};
    int top = -1;

    while(temp != NULL || top != -1){
        //left tree Traversal
        if(temp != NULL){
            stack[++top] = temp;
            temp = temp->lchild;
        }else{
            temp = stack[top--];
            printf("%d ", temp->data);
            temp = temp->rchild;
        }
    }
}

void postBiTree(const BiTree *t)
{
    BiTree *temp = t;
    BiTree *stack[STACK_SIZE] = {NULL};
    int flag[STACK_SIZE] = {0}; ////记录每个节点访问次数栈
    int top = -1;

    while(temp != NULL || top != -1){
        //left tree Traversal
        if(temp != NULL){ //第一次访问，flag置1，入栈
            stack[++top] = temp;
            flag[top] = 1;
            temp = temp->lchild;
        }else{
            if(flag[top] == 1){ ////第二次访问，flag置2，取栈顶元素但不出栈
                temp = stack[top];
                flag[top]++;
                temp = temp->rchild;
            }else{
                temp = stack[top--]; ////第三次访问，出栈
                printf("%d ", temp->data);
                temp = NULL;
            }
        }
    }
}
#endif // RECURSE

#ifdef RECURSE
void preBiTree(BiTree *t)
{
    if(t != NULL){
        printf("%d ", t->data);
        preBiTree(t->lchild);
        preBiTree(t->rchild);
    }
}

void inBiTree(BiTree *t)
{
    if(t != NULL){
        inBiTree(t->lchild);
        printf("%d ", t->data);
        inBiTree(t->rchild);
    }
}

void postBiTree(BiTree *t)
{
    if(t != NULL){
        postBiTree(t->lchild);
        postBiTree(t->rchild);
        printf("%d ", t->data);
    }
}
#endif // RECURSE


BiTree *createBiTree(void)
{
    BiTree *t;
    int num;

    t = (BiTree *)malloc(sizeof(BiTree));
    assert(t != NULL);

    scanf("%d", &num);
    if(num == 0)
        t = NULL;
    else{
        t->data = num;
        t->lchild = createBiTree();
        t->rchild = createBiTree();
    }
    return t;
}


int main(void)
{
    BiTree *t;
    t = (BiTree *)malloc(sizeof(BiTree));
    assert(t != NULL);

    t = createBiTree();

    printf("pre:\n");
    preBiTree(t);

    printf("\nin:\n");
    inBiTree(t);

    printf("\npost:\n");
    postBiTree(t);

    free(t);
}
