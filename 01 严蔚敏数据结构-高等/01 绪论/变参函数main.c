#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int demo(char*, ...);  // 声明 变参函数
int demo(char* msg, ...){
	va_list argp;   //变参指针;
	int num = 0;
	char* para;
	
	va_start(argp,msg);		// 指针指向msg的下一个参数;
	
	while(1){
		para = va_arg(argp, char*);		//获取 变参列表里 char* 类型 的 参数值;
		
		if(strcmp(para, "") == 0){
			break;
		}
		
		printf("parameter %d is: %s\n",num,para);
		num++;
	}
	
	va_end(argp);
	return 0;
}

int main(int argc, char **argv)
{
	demo("Demo","This","is","a","demo!",""); //调用变参函数
	return EXIT_SUCCESS;
}
