#include <iostream>
#include<limits>

using namespace std;

int main(void)
{
	// unsigned short 范围 
	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned short);  
	cout << "\t最大值：" << (numeric_limits<unsigned short>::max)();  
	cout << "\t最小值：" << (numeric_limits<unsigned short>::min)() << endl; 
	// 验证超出此范围的溢出
	unsigned short temp01 = -1;
	unsigned short temp02 = 65536; 
	cout << temp01<< endl;   // 此时 显示的为 65535 ,而非 -1
	cout << temp02 << endl;  // 此时 显示的为 0 ,而非 65536
	
	// unsigned short  本级 运算(short层面) 和 与其他类型的运算(自动转为最高精度)
	
	return 0;
}
