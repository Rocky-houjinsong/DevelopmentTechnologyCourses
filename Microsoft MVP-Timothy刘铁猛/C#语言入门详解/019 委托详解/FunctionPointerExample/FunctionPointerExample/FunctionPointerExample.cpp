// FunctionPointerExample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>    // 头文件导入

#pragma region 功能函数编写
int Add(int a, int b)
{
    int result = a + b;
    return result;
}

int Sub(int a, int b)
{
    int result = a - b;
    return result;
}
#pragma endregion

#pragma region 函数指针声明

/*
      函数指针的数据类型
    1. Calc  是 该函数指针的名字;
    2. 前面的 *  表明该变量为指针类型的变量
    3. 参数列表 和 返回类型需要说明
    4. typedef 是将 其定义为一种 数据类型 ;
    5. 分号表示结束,不可缺少;

*/
typedef int(*Calc)(int a, int b);   

#pragma endregion



int main()
{
    std::cout << "直接调用----------- 通过函数名进行调用\n";

    int x = 100;
    int y = 200;
    int z = 0;


    z = Add(x, y);
    printf("%d + %d = %d\n", x, y, z);

    z = Sub(x, y);
    printf("%d - %d = %d\n", x, y, z);

    std::cout << "间接调用----------- 通过函数指针进行调用\n";

    Calc funcPoint1 = &Add;
    Calc funcPoint2 = &Sub;

    z = funcPoint1(x, y);
    printf("%d + %d = %d\n", x, y, z);

    z = funcPoint2(x, y);
    printf("%d - %d = %d\n", x, y, z);

    system("pause");

    return 0;
}


