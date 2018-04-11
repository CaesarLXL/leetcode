/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 
 * The most significant digit comes first and each of their nodes contain a single digit. 
 
 * Add the two numbers and return it as a linked list.

 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Follow up:
  
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

 * Example:

 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)

 * Output: 7 -> 8 -> 0 -> 7

 * Author: Liang Xianlong

 * Date: 2018.4.11
 */

#include<iostream>
#include<stack>
using namespace::std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};


/**
 * method(1.翻转链表-->该方法运行更快)-验证通过 
 * 时间复杂度O(n)
 * 空间复杂度O(n) 
 */
/*ListNode* reverseList(ListNode* list) {
	ListNode* p = list;
	ListNode* q = list->next;
	
	while (q != NULL) {
		ListNode* t = q->next;
		q->next = p;
		p = q;
		q = t;
	}
	list->next = NULL;
	return p;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* p = reverseList(l1);
	ListNode* q = reverseList(l2);
	ListNode* list = new ListNode(0);
	ListNode* curr = list;
	
	int carry = 0;
	while (p != NULL || q != NULL) {
		int x = (p != NULL) ? p->val : 0;
		int y = (q != NULL) ? q->val : 0;
		int sum = x + y + carry;
		if (sum >= 10) {
			carry = 1;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
		} else {
			carry = 0;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
		}
		if (p != NULL) {
			p = p->next;
		}
		if (q != NULL) {
			q = q->next;
		}
	}
	if (carry > 0) {
		curr->next = new ListNode(carry);
	}
	return reverseList(list->next);
}*/

/**
 * method(2.不允许改变链表的结构-->使用栈的特性)-验证通过 
 * 时间复杂度O(n)
 * 空间复杂度O(n) 
 */
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<int> l1s;
	stack<int> l2s;
	stack<int> ls;
	
	int carry = 0;
	
	while (l1 != NULL) {
		l1s.push(l1->val);
		l1 = l1->next;
	}
	
	while (l2 != NULL) {
		l2s.push(l2->val);
		l2 = l2->next;	
	}
	
	while (!l1s.empty() || !l2s.empty()) {
		int x = (!l1s.empty()) ? l1s.top() : 0;
		int y = (!l2s.empty()) ? l2s.top() : 0;
		int sum = x + y + carry;
		if (sum >= 10) {
			carry = 1;
			ls.push(sum % 10);
		} else {
			carry = 0;
			ls.push(sum % 10);
		}
		if (!l1s.empty()) {
			l1s.pop();
		}
		if (!l2s.empty()) {
			l2s.pop();
		}
	}
	
	if (carry > 0) {
		ls.push(carry);
	}
	ListNode* list = new ListNode(0);
	ListNOde* curr = list;
	while (!ls.empty()) {
		curr->next = new ListNode(ls.top());
		ls.pop();
		curr = curr->next;
	}
	return list->next;
}

int main(void) {
	return 0;
}
