/**
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * Created by Liang.XianLong on 2018/4/17.
 */

#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head);
};

/**
 * method(1)-验证通过
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
ListNode* Solution::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* p = head;
    ListNode* q = p->next;
    while (q != nullptr) {
        ListNode* t = q->next;
        q->next = p;
        p = q;
        q = t;
    }
    head->next = nullptr;
    return p;
}

/**
 * method(2)-验证通过
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
/**
ListNode* Solution::reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *newhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}
 */

int main(void) {
    ListNode* l = new ListNode(-1);
    ListNode* head = l;
    for (int i = 0; i < 3; ++i) {
        ListNode* temp = new ListNode(i + 1);
        l->next = temp;
        l = l->next;
    }
    head = head->next;
    Solution s;
    s.reverseList(head);
    return 0;
}



