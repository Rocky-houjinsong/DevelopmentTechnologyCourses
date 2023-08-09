// 704  二分查找 -左闭右开 版本;
#include <iostream>
#include <vector>
using namespace std;
/* 
  数组的 左闭右闭 [left, right] 
  二分查找的思路就是 nums[middle]  与 target 比较 ,借助比较结果 来 调整(缩小)比较范围
  核心在于 如何确定 比较的边界值 ;
  1. left  和  right  ---- 指代 当前批次 待比较的数组 的 下标值, 所以最开始right 的值才是 nums.size() - 1; 因为数组的下标就是n-1;
  
  
  2. 存在left = right 的 比较情况,所以 left <= right,那为何存在,因为right值存在区间内,也是合理的值
  3. 为何 middle  = (left + right) /2 ; 理解, 为何 是 int middle = left + ((right - left)/2);? 防止溢出 
  此处为需要理解 
  常规的获取 middle 值 是最直接的获取中间值的办法,不考虑 类型本身的取值范围限制问题;
  但是在实际开发过程中, 一旦 (left + right)的值溢出类型的最大值,则溢出,要么为负数,要么为非常小的值,一定不是真正的中间值;
  例如 [int.min,int.max] ,第一轮取的中间值 3/2max ,直接溢出, 
  所以 是  left 加上 left到right的一般,以left为参照点来获取中间值更为合理和安全
  4. 判断之后,取middle,还是 middle +1,middle -1的问题;
  是因为 if判断中已经比较过 了 target 与 nums[middle] 的大小,且nums[middle] 是有意义(包含在整个区间内的)所以舍去;
  
  时间复杂度: O(log n)
  空间复杂度: O(1)
 */
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
		while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle; // target 在左区间，在[left, middle)中
			} else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，在[middle + 1, right)中
			} else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}
};

int main(void)
{
	Solution solution =  Solution();
	
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;
	int outcome;
	outcome = solution.search(nums,target);
	if(outcome == -1){
		cout << "未找到" << endl;
	}else if(outcome != -1){
		cout << "数组的下标为:" + outcome <<endl;
	}
	return 0;
}
