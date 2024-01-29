// 977 含负数的有序数组的平方 
#include <iostream>
#include <vector>
using namespace std;



/**
 * @file 977数组有序数组的平方双指针.cpp 
 * @brief: 
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-13 15:23:26
 * -------------------------------------------------------------
 * @Update更新:
 * @Remark备注:
 * @Advantages优点:
 * @Drawback缺点:
 * @Conditions使用条件:
 **/
class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int k = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;) { 			// 注意这里要i <= j，因为最后要处理两个元素
			if (A[i] * A[i] < A[j] * A[j])  {					// k 含义是 新数组的length
				result[k--] = A[j] * A[j];						//双指针, 不一定为指针类型, 作用是指针,指向,标志的含义,无指针语言主要是指向的含义
				j--;
			}
			else {
				result[k--] = A[i] * A[i];
				i++;
			}
		}
		return result;
	}
};

int main(void)
{
	Solution solution =  Solution();
	
	vector<int> nums = {-7,-3,2,3,11};
	int target = 2;
	vector<int> outcome;
	outcome = solution.sortedSquares(nums);
	
	for(int i=0;i<outcome.size();i++){
		cout <<outcome[i]<<","<<endl;		
	}
	
	return 0;
}
