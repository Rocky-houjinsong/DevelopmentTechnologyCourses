//27 数组  移除元素 相对双指针 元素顺序可以改变 
#include <iostream>
#include <vector>
using namespace std;

/**
 * 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;
		while (leftIndex <= rightIndex) {
			// 找左边等于val的元素
			while (leftIndex <= rightIndex && nums[leftIndex] != val){
				++leftIndex;									
			}
			// 找右边不等于val的元素
			while (leftIndex <= rightIndex && nums[rightIndex] == val) {
				-- rightIndex;
			}
			// 将右边不等于val的元素覆盖左边等于val的元素
			if (leftIndex < rightIndex) {
				nums[leftIndex++] = nums[rightIndex--];
			}
		}
		return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
	}
};

int main(void)
{
	Solution solution =  Solution();
	
	vector<int> nums = {0,1,2,2,3,0,4,2};
	int target = 0;
	int outcome;
	outcome = solution.removeElement(nums,target);
	if(outcome == -1){
		cout << "未找到" << endl;
	}else if(outcome != -1){
		cout << "原数组的长度是:"<<nums.size()<<" 新数组的长度为:"<<outcome <<endl;    // 打印输出中 字符串 与 变量的 拼接方式
	}
	return 0;
}
