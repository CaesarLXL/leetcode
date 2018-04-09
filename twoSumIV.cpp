/*
Given a Binary Search Tree and a target number, return true if there exist 

two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

Author: Liang Xianlong

Date: 2018.4.9
*/

#include<iostream>
#include<vector>
#include<map>
using namespace::std;

/*
Definition for a binary tree node.
*/
struct TreeNode {
	int val;
 	TreeNode *left;
	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	bool findTarget(TreeNode* root, int k);
};

void pushNodeValueToVector(TreeNode* root, vector<int>& treeNodes) {
	if (root != NULL) {
		treeNodes.push_back(root->val);
		pushNodeValueToVector(root->left, treeNodes);
		pushNodeValueToVector(root->right, treeNodes);
	}
}

/*
*method(1)-验证通过 
*时间复杂度O(n)
*空间复杂度O(n) 
*/
bool Solution::findTarget(TreeNode* root, int k) {
	if (root == NULL) {
		return false;
	}
	map<int, int> imap;
	vector<int> treeNodes;
	pushNodeValueToVector(root, treeNodes);
	for (int i = 0; i < treeNodes.size(); ++i) {
		imap.insert(pair<int, int>(treeNodes[i], i));
	}
	for (int i = 0; i < treeNodes.size(); ++i) {
		int val = k - treeNodes[i];
		if (imap.find(val) != imap.end() && imap[val] != i){
			return true;
		}
	}
	return false;
}

int main(void){
	return 0;
}
