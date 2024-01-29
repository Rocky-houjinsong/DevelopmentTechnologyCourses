
#include <iostream>
#include <vector>

/**
 * @file 344.反转字符串01双指针法.cpp 
 * @brief: 
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-13 16:19:08
 * -------------------------------------------------------------
 * @Update更新:
 * @Remark备注:
 * @Advantages优点:
 * @Drawback缺点:
 * @Conditions使用条件:
 **/
using namespace std;
class Solution {
public :
	void reverseString(vector<char>& s){
		for(int i = 0,j = s.size()-1 ;i < s.size()/2;i++,j--){
			swap(s[i],s[j]);                                              // 该函数 将指定两个元素交换
		}
	}

};

int main(void)
{
	Solution solution =  Solution();
	
	vector<char> nums = {'H','e','l','l','o','W','o','r','l','d'};

	solution.reverseString(nums);
	
	for(int i=0; i< nums.size();i++){
		std::cout <<nums[i] << " ";
	}

	return 0;
}
