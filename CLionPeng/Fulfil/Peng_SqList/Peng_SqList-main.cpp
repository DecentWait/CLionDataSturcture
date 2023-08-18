#include <cstdio>
#include "Peng_SqList.h"

Status Compare_Implement(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

void Visit_Implement(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char **argv) {
    SqList L;
    int i;
    ElemType e;

    printf("████████ InitList \n");
    {
        printf("█ 初始化顺序表 L ...\n");
        InitList(L);
    }

    printf("████████ ListEmpty \n");
    {
        if (ListEmpty(L) == TRUE) {
            printf("█ L 为空！！\n");
        } else {
            printf("█ L 不为空！\n");
        }
    }

    printf("████████ ListInsert \n");
    {
        for (i = 1; i <= 8; i++) {
            printf("█ 作为示范，在 L 第 %d 个位置插入 \"%d\"...\n", i, 2 * i);
            ListInsert(L, i, 2 * i);
        }
    }

    printf("████████ TraverseList \n");
    {
        printf("█ L 中的元素为: L = ");
        TraverseList(L);
    }

    printf("████████ ListLength \n");
    {
        i = ListLength(L);
        printf("█ L 的长度为: %d \n", i);
    }

    printf("████████ ListDelete \n");
    {
        printf("█ 删除前的元素: L = ");
        TraverseList(L);
        printf("█ 尝试删除 L 中第 6 个元素...\n");
        ListDelete(L, 6, e);
        printf("█ 删除后的元素: L = ");
        TraverseList(L);
        printf("█ 被删除元素是: \"%d\"\n", e);
    }

    printf("████████ GetElem \n");
    {
        GetElem(L, 4, e);
        printf("█ L 中第 4 个位置的元素为: \"%d\" \n", e);
    }

    printf("████████ LocateElem \n");
    {
        i = LocateElem(L, 7);
        printf("█ L 中第一个元素值大于 \"7\" 的元素为: \"%d\" \n", L.elem[i - 1]);
    }

    printf("████████ ClearList \n");
    {
        printf("█ 清空 L 前: ");
        if (ListEmpty(L) == TRUE) {
            printf(" L 为空！！\n");
        } else {
            printf(" L 不为空！\n");
        }
        ClearList(L);
        printf("█ 清空 L 后: ");
        if (ListEmpty(L) == TRUE) {
            printf(" L 为空！！\n");
        } else {
            printf(" L 不为空！\n");
        }
    }

    printf("████████ DestroyList \n");
    {
        printf("█ 销毁 L 前: ");
        if (L.elem != nullptr) {
            printf(" L 存在！\n");
        } else {
            printf(" L 不存在！！\n");
        }
        DestroyList(L);
        printf("█ 销毁 L 后: ");
        if (L.elem != nullptr) {
            printf(" L 存在！\n");
        } else {
            printf(" L 不存在！！\n");
        }
    }

    return 0;
}
