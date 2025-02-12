#include <stddef.h>
#include "ll_cycle.h"

static int ll_has_cycle_helper(node **tortoise, node **hare, int count);
/*
*  如果没有循环返回0，有循环返回1
*  兔子结点在前，乌龟结点在后，如果兔子结点前进途中1：碰到乌龟结点 有循环、2：碰到NULL 无循环
*　可以通过编写辅助函数如：ifistortoise ifisnull 以及 使用递归函数来判断
*/
int ll_has_cycle(node *head) {
    if (head == NULL) {
        return 0;
    }
    node *tortoise = head;
    node *hare = head->next;

    return ll_has_cycle_helper(&tortoise, &hare, 0);
}

static int ll_has_cycle_helper(node **tortoise, node **hare, int count) {
    if (*hare == NULL) {
        return 0;
    }
    if (*hare == *tortoise) {
        return 1;
    }
    if (count == 2) {
        *tortoise = (*tortoise)->next;
        return ll_has_cycle_helper(tortoise, hare, 0);
    }
    *hare = (*hare)->next;
    return ll_has_cycle_helper(tortoise, hare, count + 1);
}