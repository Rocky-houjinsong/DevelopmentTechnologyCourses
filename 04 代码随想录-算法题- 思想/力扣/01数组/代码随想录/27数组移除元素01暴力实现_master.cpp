//27 数组 移除元素 在 数组nums中移除 值等于val,返回新数组的长度
//该方法随着 数据规模增长而增长
// 该方法 求的不仅仅是 新数组的长度了, 连 新数组本身都求出来
// 思路: 求出新数组, 来求 新数组的长度 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		
		int size = nums.size();
		
		for (int i = 0; i < size; i++) {		// i,j均为下标
			if (nums[i] == val) { 							
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];					// 发现需要移除的元素后，就将数组集体向前移动一位
				}
				i--; 										// 移除该轮特定元素后, 下标i此时指代元素是未判定, i--,进行下轮判定
				size--; 									// 此时数组的大小-1
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
