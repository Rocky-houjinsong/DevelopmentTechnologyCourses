#include <iostream>    // 输入输出流
#include <vector>	  // 数组
#include <algorithm>  //通用算法

using namespace std;

/**
 * @file 541.反转字符串II01.cpp 
 * @brief: 
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-18 16:07:27
 * -------------------------------------------------------------
 * @Update更新:  此处需要观看视频 理解 :https://www.bilibili.com/video/BV1dT411j7NN
 * @Remark备注:  当需要固定规律一段一段去处理字符串的时候，要想想在在for循环的表达式上做做文章
 * @Advantages优点:
 * @Drawback缺点:
 * @Conditions使用条件:
 **/
class Solution {
public :
	string reverseStr(string s,int k) {
		for(int i = 0; i < s.size(); i+=(2 * k)){
			// 1.每隔 2K 个字符的前K个字符进行反转 
			// 2.剩余字符 小于2K但大于等于 K个,则反转前K个字符
			if(i + k <= s.size()){
				reverse(s.begin() + i,s.begin() + i + k);
			}else {
				// 3. 剩余字符 少于 K个, 则将剩余字符 全部反转
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}
};


int main(void)
{
	Solution solution =  Solution();
	string output;

	std::cout <<"请输入要反转的字符串, 输入-1则 退出程序"<<std::endl;
	
	while(1){
		std::string inputStr;
		std::cin >> inputStr;
		if(inputStr == "-1"){
			break;
		}
		
		output = solution.reverseStr(inputStr,2);
		std::cout << "反转后的字符串是:" << output << std::endl;
	}
	
	return 0;
}
