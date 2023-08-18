#ifndef SQLIST_H
#define SQLIST_H

#include <cstdio>
#include <cstdlib>
#include <string>

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

Status InitList(SqList &L);

void Error(const char *s);

Status DestroyList(SqList &L);

Status ClearList(SqList &L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType &e);

int LocateElem(SqList L, ElemType e);

void ListInsert(SqList &L, int i, ElemType e);

void Increment(SqList &L);

void ListDelete(SqList &L, int i, ElemType &e);

void TraverseList(SqList L);

#endif
