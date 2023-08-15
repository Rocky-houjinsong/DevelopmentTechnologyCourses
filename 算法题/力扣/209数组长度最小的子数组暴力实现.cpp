// 209 数组 长度最小的子数组 , 暴力解法
#include <iostream>
#include <vector>
using namespace std;

#define INT32_MAX __INT_MAX__   //定义 int类型最大值;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX; 					// 最终的结果
		int sum = 0; 								// 子序列的数值之和
		int subLength = 0; 							// 子序列的长度,当前批次下的
		for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
			sum = 0;
			for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
				sum += nums[j];
				if (sum >= s) { // 一旦发现子序列和超过了s，更新result
					subLength = j - i + 1; // 取子序列的长度
					result = result < subLength ? result : subLength;
					break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
				}
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
