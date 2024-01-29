//27 数组  移除元素 相对双指针 元素顺序可以改变 
#include <iostream>
#include <vector>
using namespace std;

/**
 * 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

/**
 * @file 27数组移除元素03相向双指针思路.cpp 
 * @brief: 
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-13 15:02:07
 * -------------------------------------------------------------
 * @Update更新:
 * @Remark备注:01:前递/后递 看你需要返回的是 哪一个值; 02 循环下 多指针 可以看成常量
 * @Advantages优点:
 * @Drawback缺点:
 * @Conditions使用条件: 01:原地移除,O(1)空间;  02:元素顺序不允许改变; 03:时间复杂度低
 **/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;
		
		while (leftIndex <= rightIndex) {
			//Core 左边直接存储 新元素													// 找左边等于val的元素
			while (leftIndex <= rightIndex && nums[leftIndex] != val){					//rightIndex在每次循环中 认定为常量
				++leftIndex;															// 使用递增后的值
			}
			//Core 右边排除元素,直到遇到新元素										   // 找右边不等于val的元素
			while (leftIndex <= rightIndex && nums[rightIndex] == val) {			   // 使用递减后的值 
				-- rightIndex;
			}
			//Core 右边元素交给左边	(右边每次只有一个元素交给左边)					   // 将右边不等于val的元素覆盖左边等于val的元素
			if (leftIndex < rightIndex) {
				nums[leftIndex++] = nums[rightIndex--]; 							   //使用 递增递减前的值
			}
		}
		return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
	}
};

int main(void)
{
	Solution solution =  Solution();
	
	vector<int> nums = {0,1,2,2,3,0,4,2,0,02};
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
