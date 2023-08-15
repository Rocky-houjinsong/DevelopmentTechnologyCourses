//27 数组 移除元素 在 数组nums中移除 值等于val,返回新数组的长度
#include <iostream>
#include <vector>
using namespace std;


// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];
				}
				i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
				size--; // 此时数组的大小-1
			}
		}
		return size;
		
	}
};

int main(void)
{
	Solution solution =  Solution();
	
	vector<int> nums = {0,1,2,2,3,0,4,2};
	int target = 2;
	int outcome;
	outcome = solution.removeElement(nums,target);
	if(outcome == -1){
		cout << "未找到" << endl;
	}else if(outcome != -1){
		cout << "原数组的长度是"<<nums.size()<<"新数组的长度为:"<<outcome <<endl;    // 打印输出中 字符串 与 变量的 拼接方式
	}
	return 0;
}
