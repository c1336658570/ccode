#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

//递归
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *newhead =  reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

//循环
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL, *next, *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}