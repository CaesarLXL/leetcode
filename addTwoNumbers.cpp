/*
You are given two non-empty linked lists representing two non-negative integers. 

The digits are stored in reverse order and each of their nodes contain a single digit. 

Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

Explanation: 342 + 465 = 807.

Author: Liang Xianlong

Date: 2018.4.10
*/


#include<iostream>
#include<vector>
using namespace::std;


/*
Definition for singly-linked list.
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

/*
*method(1)-验证通过 
*时间复杂度O(n)
*空间复杂度O(n) 
*/
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	vector<int> l1v;
	vector<int> l2v;
	vector<int> lv;
	while (l1 != NULL) {
		l1v.push_back(l1->val);
		l1 = l1->next;
	}
	while (l2 != NULL) {
		l2v.push_back(l2->val);
		l2 = l2->next;
	}
	
	if (l1v.size() > l2v.size()) {
		int temp = 0;
		int index = 0;
		for (int i = 0; i < l2v.size(); ++i) {
			int sum = l1v[index++] + l2v[i] + temp;
			if (sum >= 10) {
				temp = 1;
				lv.push_back(sum % 10); 
			} else {
				temp = 0;
				lv.push_back(sum % 10);
			}
		}
		for (int i = index; i < l1v.size(); ++i) {
			int sum = l1v[i] + temp;
			if (sum >= 10) {
				temp = 1;
				lv.push_back(sum % 10); 
			} else {
				temp = 0;
				lv.push_back(sum % 10);
			}
		}
		if (temp > 0) {
			lv.push_back(temp);
		}
	} else if (l1v.size() == l2v.size()) {
		int temp = 0;
		for (int i = 0; i < l1v.size(); ++i) {
			int sum = l1v[i] + l2v[i] + temp;
			if (sum >= 10) {
				temp = 1;
				lv.push_back(sum % 10); 
			} else {
				temp = 0;
				lv.push_back(sum % 10);
			}
		}
		if (temp > 0) {
			lv.push_back(temp);
		}
	} else {
		int temp = 0;
		int index = 0;
		for (int i = 0; i < l1v.size(); ++i) {
			int sum = l1v[i] + l2v[index++] + temp;
			if (sum >= 10) {
				temp = 1;
				lv.push_back(sum % 10); 
			} else {
				temp = 0;
				lv.push_back(sum % 10);
			}
		}
		for (int i = index; i < l2v.size(); ++i) {
			int sum = l2v[i] + temp;
			if (sum >= 10) {
				temp = 1;
				lv.push_back(sum % 10); 
			} else {
				temp = 0;
				lv.push_back(sum % 10);
			}
		}
		if (temp > 0) {
			lv.push_back(temp);
		}
	}
	
	ListNode* list = NULL;
	if (lv.size() > 0) {
		list = new ListNode(lv[0]);
		ListNode* temp = list;
		for (int j = 1; j < lv.size(); ++j) {
			ListNode* ltemp = new ListNode(lv[j]);
			temp->next = ltemp;
			temp = temp->next;
		}
	}
	return list;
}

int main(void) {
	return 0;
}
