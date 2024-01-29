//209 数组  长度最小的子数组 双指针思路 滑动窗口
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
//并返回其长度。如果不存在符合条件的子数组，返回 0 。
//PS:隐喻
#include <iostream>
#include <vector>
using namespace std;

#define INT32_MAX __INT_MAX__   //定义 int类型最大值;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;
		// 窗口的  3个属性  ----------- 窗口值, 窗口左边, 窗口长度
		int sum = 0; // 滑动窗口数值之和
		int i = 0; // 滑动窗口起始位置
		int subLength = 0; // 滑动窗口的长度
		
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];
			// 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
			while (sum >= s) {
				subLength = (j - i + 1); // 取子序列的长度
				result = result < subLength ? result : subLength;
				sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
			}
		}
		// 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
		return result == INT32_MAX ? 0 : result;
	}
};

int main(void)
{
	Solution solution =  Solution();
	
	vector<int> nums = {2,3,1,2,4,3};
	int target = 7;
	int outcome;
	outcome = solution.minSubArrayLen(target,nums);
	
	cout << "数组的最小长度连续子数组的长度是: "<<outcome <<endl;
	
	return 0;
}
