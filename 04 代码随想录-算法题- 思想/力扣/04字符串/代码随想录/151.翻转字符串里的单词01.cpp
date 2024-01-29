//源字符串为："the sky is blue "
//
//移除多余空格 : "the sky is blue"
//字符串反转："eulb si yks eht"
//单词反转："blue is sky the"

#include <iostream>
using namespace std;      // string& 声明需要

/**
 * @file 151.翻转字符串里的单词01.cpp 
 * @brief: 
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-18 16:49:58
 * -------------------------------------------------------------
 * @Update更新:   
 * @Remark备注:
 * @Advantages优点:    不要使用辅助空间，空间复杂度要求为O(1)。
 * @Drawback缺点:
 * @Conditions使用条件:
 **/
class Solution
{
public:
	//去除所有空格,并在相邻单词之间 添加空格, 快慢指针 
	void removeExtraSpaces(string& s)
	{
		int slowIndex = 0, fastIndex = 0; 			// 定义 快指针, 慢指针
		//去掉字符串前面的空格
		while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' '){
			fastIndex++;													
		}
		
		for(;fastIndex < s.size();fastIndex++){
			// 去掉字符串中间部分的冗余空格
			if(fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' '){  //存在连续至少两个空格时,
				continue;
			}else{
				s[slowIndex++] = s[fastIndex];
			}
		}
		// 去掉字符串末尾的空格
		if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' '){
			s.resize(slowIndex - 1);
		}else{
			s.resize(slowIndex);    //重设字符串大小
		}
	}
	
	//翻转, 区间写法,左闭右闭 []
	void reverse(string& s,int start, int end)
	{
		for(int i = start,j = end; i < j; i++, j--)
		{
			swap(s[i] , s[j]);
		}
	}
	
	string reverseWords(string s)
	{
		removeExtraSpaces(s);
		reverse(s,0,s.size() - 1);
		int start = 0;
		for(int i = 0; i <= s.size(); ++i)
		{
			
		}	
		
	}
};
