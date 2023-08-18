#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>         // 提供malloc、realloc、free、exit原型

#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          (-1)
#define OVERFLOW            (-2)

#ifndef NULL
#define NULL ((void*)0)
#define NULL nullptr
#define NULL __null
#endif

#define LIST_INIT_SIZE      100
#define LIST_INCREMENT       10

typedef int Status;

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList(SqList *L);

Status DestroyList(SqList *L);

Status ClearList(SqList *L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType *e);

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

Status ListInsert(SqList *L, int i, ElemType e);

Status ListDelete(SqList *L, int i, ElemType *e);

void ListTraverse(SqList L, void (Visit)(ElemType));

#endif
