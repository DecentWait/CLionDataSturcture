#include "Yan_SqList.h"

Status InitList(SqList *L) {
    (*L).elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!(*L).elem) exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList *L) {
    if (!L || !(*L).elem) return ERROR;
    free((*L).elem);
    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
    return OK;
}

Status ClearList(SqList *L) {
    if (!L || !(*L).elem) return ERROR;
    (*L).length = 0;
    return OK;
}

Status ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

int ListLength(SqList L) {
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length) return ERROR;
    *e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    ElemType *p;

    if (!L.elem) return ERROR;
    i = 1;
    p = L.elem;
    while (i <= L.length && !Compare(*p++, e)) ++i;
    if (i <= L.length) return i;
    else return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) {
    int i;

    if (!L.elem || L.length < 2) return ERROR;
    i = 0;
    while (i < L.length && L.elem[i] != cur_e) ++i;
    if (i == 0 || i >= L.length) return ERROR;
    *pre_e = L.elem[i - 1];
    return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    int i;

    if (!L.elem || L.length < 2) return ERROR;
    i = 0;
    while (i < L.length - 1 && L.elem[i] != cur_e) ++i;
    if (i >= L.length - 1) return ERROR;
    *next_e = L.elem[i + 1];

    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    ElemType *newbase;
    ElemType *p, *q;

    if (!L || !(*L).elem) return ERROR;
    if (i < 1 || i > (*L).length + 1) return ERROR;
    if ((*L).length >= (*L).listsize) {
        newbase = (ElemType *) realloc((*L).elem, ((*L).listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newbase)exit(OVERFLOW);
        (*L).elem = newbase;
        (*L).listsize += LIST_INCREMENT;
    }
    q = &(*L).elem[i - 1];
    for (p = &(*L).elem[(*L).length - 1]; p >= q; --p) *(p + 1) = *p;
    *q = e;
    ++(*L).length;

    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    ElemType *p, *q;

    if (!L || !(*L).elem) return ERROR;
    if (i < 1 || i > (*L).length) return ERROR;
    p = &(*L).elem[i - 1];
    *e = *p;
    q = (*L).elem + (*L).length - 1;
    for (++p; p <= q; ++p) *(p - 1) = *p;
    --(*L).length;

    return OK;
}

void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;
    for (i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }
    printf("\n");
}
