#include <iostream>   					// 头文件 --- 导入封装好的函数
/*
  头文件中 特殊区块(区域) --- 避免与其他文件重名无法识别风险
  cout,endl等 命令都存储里面,无std而单独使用cout则报错
 */
using namespace std;   

int main(char* argc[],int argv)          // main函数, --- 程序唯一入口; void 空类型,万能类型;  int main(void) 
{
	cout << argv << endl;     			// argv 存储 argc元素个数;
	cout << "Hello World!" << endl;
	/*
	    temp01 为变量  int 为类型  ---- 类型的变量的蓝图, int 是有取值范围, 
	    10 为 整数字面量 ,为常量 ,赋值给 temp01 ----- 变量的值 
	    int temp01 = 10;   声明变量,并进行初始化   --- 建议 声明的同时,进行初始化操作
	 */
	int temp01 = 10;   
	char temp02 = 'a'; 
	double temp03;  // 变量的 声明,可以不必同时初始化
	unsigned short d = 65536; // 测试为最大值,再加一 则 溢出
	cout << d <<endl;
	bool  flag = false;  //布尔类型
	
	// cout 用来输出, 谁是输入呢? cin 
	// ;  语句的分隔符;
	
	return 0;          // 函数必须有返回值 ;(至少一个输入,可以没有输入)
}


/*
  cout 用来输出内容  一般格式为  cout << 输出内容 << ;
  其中  输出内容 的格式,编译器自动识别,无需 类似C中需要手动书写,  可读性高,但是编译效率不如 C;
  endl 类似换行符,但是 与 换行符\n 还是有区别的; 到时进行重新比较 ;
  
 */


