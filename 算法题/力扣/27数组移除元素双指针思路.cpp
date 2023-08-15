// 27 数组  移除元素  双指针思路
#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
//  不改变元素的相对位置
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int slowIndex = 0;													//慢指针, 指向新数组的下标
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (val != nums[fastIndex]) {
				nums[slowIndex++] = nums[fastIndex];						//快指针,指向符合新数组的元素
			}
		}
		return slowIndex;
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
		cout << "原数组的长度是:"<<nums.size()<<" 新数组的长度为:"<<outcome <<endl;    // 打印输出中 字符串 与 变量的 拼接方式
	}
	return 0;
}
