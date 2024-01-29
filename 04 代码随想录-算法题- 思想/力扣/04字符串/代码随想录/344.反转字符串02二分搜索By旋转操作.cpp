// 反转是 旋转的一种特殊 方式 ,  灵感来自 <编程珠玑> 2.3 基本操作的威力
#include <iostream>
#include <vector>


/**
 * @file 344.反转字符串02二分搜索By旋转操作.cpp 
 * @brief:    待实现, 使用翻转操作
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-13 16:22:12
 * -------------------------------------------------------------
 * @Update更新:
 * @Remark备注:
 * @Advantages优点:
 * @Drawback缺点:
 * @Conditions使用条件:
 **/
using namespace std;
class Solution 
{
public :
	void reverseString(vector<char>& s){
		for(int i = 0,j = s.size()-1 ;i < s.size()/2;i++,j--){
			swap(s[i],s[j]);
//			s.reserve(0,i);
//			s.reserve(i,s.size()-2);
//			s.reserve(0,s.size()-2);
		}
		
	}
	

};
