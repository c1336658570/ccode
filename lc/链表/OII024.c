/*
剑指 Offer II 024. 反转链表
给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
*/

#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *p, *q, *r;
    q = head;
    p = head->next;
    head->next = NULL;

    while (p != NULL)
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }

    return q;
}

struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}