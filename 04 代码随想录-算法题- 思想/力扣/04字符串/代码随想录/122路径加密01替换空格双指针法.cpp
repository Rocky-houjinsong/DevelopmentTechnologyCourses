#include <iostream>


/**
 * @file 122路径加密01替换空格双指针法.cpp 
 * @brief: 获取 插入后的长度,从后插入
 * @version: v0.0.1 
 * @author: Rocky.houjinSong
 * @date: 2024-01-15 15:57:33
 * -------------------------------------------------------------
 * @Update: 01
 * @Update: 02
 **/
class Solution{
public:
	string replaceSpace(string s){
	int count = 0;// 统计空格个数
	int soldSize =  s.size();

	for(int i = 0; i <= s.size(); i++){
		if(s[i] == ' '){
			count++;
		}
	}
	
	s.resize(s.size() + count * 2);
		
		
	}
};
