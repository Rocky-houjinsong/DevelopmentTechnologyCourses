//给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
//例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
//对于输入字符串 "a5b"，函数应该将其转换为 "anumberb"
//输入：一个字符串 s,s 仅包含小写字母和数字字符。
//输出：打印一个新的字符串，其中每个数字字符都被替换为了number
//样例输入：a1b2c3
//样例输出：anumberbnumbercnumber
//数据范围：1 <= s.length < 10000。

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int count = 0; //统计数字的个数 
		int sOldSize = s.size();  // 字符串原本的长度
		for(int i=0;i < s.size();i++){
			if(s[i] >= '0' && s[i] <= '9'){
				count++; 							// 获取数字个数
			}
		}
		
		s.resize(s.size() + count * 5);				// 扩充
		int sNewSize = s.size();
		for(int i = sNewSize -1, j = sOldSize -1; j < i; i--, j--){
			if(s[j] > '9' || s[j] < '0'){
				s[i] = s[j];
			}else
			{
				s[i] = 'r';
				s[i - 1] = 'e';
				s[i - 2] = 'b';
				s[i - 3] = 'm';
				s[i - 4] = 'u';
				s[i - 5] = 'n';
				i -= 5;
			}
		}
		cout << s << endl;
	}
	
	
	return 0;
}
