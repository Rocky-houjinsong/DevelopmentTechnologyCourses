// abc, acb, bac, bca, cab, cba; 3 * 2 *1;

//思路:  第一个 后后面的全排列

#include <iostream>   //cout 需要
#include <cassert>    //assert需要
using namespace std;
class Solution
{
public:
	void Permutation(std::string pStr, size_t pBegin)
	{
		//当条件不满足时，assert 会触发断言失败，程序会停止运行，并输出相关信息，帮助你定位错误。
		//在发布版本的代码中，断言通常被禁用，因为它们只在调试阶段有用
	//	assert(pBegin >= 0 && pBegin<pStr.length());
		
		if(pBegin == pStr.length() - 1)
			std::cout << pStr << std::endl;
		else
		{
			for(size_t i=pBegin;i < pStr.length(); i++)
			{
				std::swap(pStr[pBegin],pStr[i]);
				Permutation(pStr,pBegin + 1);   //回溯
				std::swap(pStr[pBegin],pStr[i]);
			}
		}
	}
};

int main(void)
{
	Solution solution =  Solution();
	std::string str = "abc";
	solution.Permutation(str,0);

	return 0;

}
