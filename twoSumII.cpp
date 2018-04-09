/*
*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

*The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 

*Please note that your returned answers (both index1 and index2) are not zero-based.

*You may assume that each input would have exactly one solution and you may not use the same element twice.

*Input: numbers={2, 7, 11, 15}, target=9

*Output: index1=1, index2=2

* Author: Liang Xianlong
*
* Date: 2018.4.9
*/

#include<iostream>
#include<vector>
#include<map>

using namespace::std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

/*
*method(1)-验证通过 
*时间复杂度O(n)
*空间复杂度O(n) 
*/
vector<int> Solution::twoSum(vector<int>& numbers, int target){
	map<int, int> imap;
	map<int, int>::iterator iter;
	vector<int> indexs;
	for(int i = 0; i < numbers.size(); ++i){
		imap.insert(pair<int, int>(numbers[i], i));
	}
	for(int i = 0; i < numbers.size(); ++i){
		int val = target - numbers[i];
		if(imap.find(val) != imap.end() && imap[val] != i){
			if (i > imap[val]){
				indexs.push_back(imap[val] + 1);
				indexs.push_back(i + 1);
			}else{
				indexs.push_back(i + 1);
				indexs.push_back(imap[val] + 1);	
			}
			return indexs;
		}
	}
	return indexs;
}

int main(void){
	int in[] = { 2, 7, 11, 15 };
    vector<int> input(in, in + 4);
    Solution s;
    vector<int> output = s.twoSum(input, 9); 
    for (int i = 0; i < output.size(); ++i){
    	cout << output[i] << endl;
    }
    return 0;
}

