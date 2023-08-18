#include "Peng_SqList.h"
#include <iostream>

using namespace std;

Status InitList(SqList &L) {
    L.elem = new ElemType[LIST_INIT_SIZE];
    if (!L.elem) Error("Overflow!");
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

void Error(const char *s) {
    cout << s << endl;
    exit(1);
}

Status DestroyList(SqList &L) {
    delete[] L.elem;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

Status ClearList(SqList &L) {
    L.length = 0;
    return OK;
}

Status ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

int ListLength(SqList L) {
    return L.length;
}

int GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e) {
    ElemType *p;
    int i = 1;
    p = L.elem;
    while ((i <= L.length) && (*p++ != e))i++;
    if (i <= L.length)return i;
    else return 0;
}

void ListInsert(SqList &L, int i, ElemType e) {
    ElemType *q, *p;
    if ((i < 1) || (i > L.length + 1)) Error("Position Error!");
    if (L.length >= L.listsize) Increment(L);
    q = &(L.elem[i - 1]);
    for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
    *q = e;
    ++L.length;
}

void Increment(SqList &L) {
    ElemType *newlist;
    newlist = new ElemType[L.listsize + LIST_INCREMENT];
    if (!newlist) Error("Overflow!");
    for (int i = 0; i < L.length; i++) newlist[i] = L.elem[i];
    delete[] L.elem;
    L.elem = newlist;
    L.listsize += LIST_INCREMENT;
}

void ListDelete(SqList &L, int i, ElemType &e) {
    ElemType *p, *q;
    if ((i < 1) || (i > L.length)) Error("Position Error!");
    e = L.elem[i - 1];
    p = &(L.elem[i - 1]);
    q = L.elem + L.length - 1;
    for (++p; p <= q; ++p) *(p - 1) = *p;
    --L.length;
}

void TraverseList(SqList L) {
    int i;
    ElemType *p;
    if (L.length != 0) {
        i = 1;
        p = L.elem;
        while (i <= L.length) {
            cout << *p++ << " ";
            i++;
        }
    }
    printf("\n");
}
