/*
定一个链表的 头节点 head ，请判断其是否为回文链表。
如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

示例 1：
输入: head = [1,2,3,3,2,1]
输出: true

示例 2：
输入: head = [1,2]
输出: false
*/

#include <stdbool.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    struct ListNode *p, *q, *r, *t;
    p = q = head;
    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    if (q != NULL)
    {
        p = p->next;
    }
    t = p->next;
    p->next = NULL;
    while (t != NULL)
    {
        r = t->next;
        t->next = p;
        p = t;
        t = r;
    }
    q = head;
    while (p != NULL && p->val == q->val)
    {
        p = p->next;
        q = q->next;
    }
    if (p == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
