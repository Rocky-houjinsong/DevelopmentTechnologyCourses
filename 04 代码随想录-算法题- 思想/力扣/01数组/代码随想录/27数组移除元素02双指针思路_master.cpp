// 27 数组  移除元素  双指针思路
// 目的是获取新数组的长度(符合新数组的元素数量),而非求新数组, 通过慢指针 
// 一轮 循环 即可, 不会随着 数据规模的 增大而增大 ;
// 好比 快指针 在前面 挑挑拣拣, 符合的 告诉 慢指针一声, 慢指针只需要记录 即可;
// 思路/本质: 按条件 对元素本身进行判断
#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
/*
 * -------------------------------------------------------------
 * @Update更新:
 * @Remark备注: 剔除元素(组装新数组)的同时, 计算新数组的长度   :  利用 索引的双重身份 : 指针 / (长度 = 索引 -1)
 * @Advantages优点: 
 * @Drawback缺点:
 * @Conditions使用条件: 01:原地移除,O(1)空间;  02:元素顺序不允许改变; 03:时间复杂度低
 **/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int slowIndex = 0;													
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (val != nums[fastIndex]) {									//快指针,指向符合新数组的元素
				//Core Code核心代码: 更新新数组						
				nums[slowIndex++] = nums[fastIndex];						
			}
		}
		return slowIndex; 														//慢指针, 指向新数组的下标
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
