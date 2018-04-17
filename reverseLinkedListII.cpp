/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reverselinkedListII.cpp
 * Author: liangxianlong
 *
 * Created on April 17, 2018, 10:32 PM
 */

/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.

 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,

 * return 1->4->3->2->5->NULL.

 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

#include <iostream>
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
          ListNode* reverseBetween(ListNode* head, int m, int n);
  };

/*
*method(1)-验证通过 
*时间复杂度O(n)
*空间复杂度O(n) 
*/
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if (head->next == NULL) {
        return head;
    }
    ListNode* ph = new ListNode(-1);
    ph->next = head;
    ListNode* p = ph;
    ListNode* q = NULL;
    ListNode* t = NULL;
    for (int i = 0; i < n; ++i) {
        if (i < m - 1) {
            p = p->next;
        } else if (i == m - 1) {
            q = p->next;
            t = q->next;
        } else {
            q->next = t->next;
            t->next = p->next;
            p->next = t;
            t = q->next;
        }
    }
        return ph->next;
}
  
/*
 * 
 */
int main(int argc, char** argv) {
    cout << "hello, world" << endl;
    return 0;
}
