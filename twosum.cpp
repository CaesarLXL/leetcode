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
*时间复杂度O(n2)
*空间复杂度O(n) 
*/
/*vector<int> Solution::twoSum(vector<int>& nums, int target){
	vector<int> indexs;
	for(int i = 0; i < nums.size(); ++i){
		for(int j = i + 1; j < nums.size(); ++j){
			if(nums[i] + nums[j] == target){
				indexs.push_back(i);
				indexs.push_back(j);
				return indexs;
			}
		}
	}
	return indexs;
}*/


/*
*method(2)-验证通过 
*时间复杂度O(n)
*空间复杂度O(n) 
*/
vector<int> Solution::twoSum(vector<int>& nums, int target){
	map<int, int> imap;
	map<int, int>::iterator iter;
	vector<int> indexs;
	for(int i = 0; i < nums.size(); ++i){
		imap.insert(pair<int, int>(nums[i], i));
	}
	
	for (int i = 0; i < nums.size(); ++i){
		int val = target - nums[i];
		if (imap.find(val) != imap.end() && imap[val] != i){
			indexs.push_back(i);
			indexs.push_back(imap[val]);
			return indexs;
		}
	}
	return indexs;
}

int main(void){
	int in[] = { 3, 2, 4 };
    vector<int> input(in, in + 3);
    Solution s;
    vector<int> output = s.twoSum(input, 6); 
    for (int i = 0; i < output.size(); ++i){
    	cout << output[i] << endl;
    }
    return 0;
}
