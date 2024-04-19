// INC_03_SELECTION_SORT_GENERATE_TEST_CASE_SORTTESTHELPER_H

#ifndef  INC_03_SELECTION_SORT_GENERATE_TEST_CASE_SORTTESTHELPER_H
#define  INC_03_SELECTION_SORT_GENERATE_TEST_CASE_SORTTESTHELPER_H
#include <iostream>  //
#include <ctime>    //
#include <cassert>  //

using namespace std;
namespace SortTestHelper{
	
	//生成有 n个元素的随机数组, 每个数组的随机范围是 (rangeL,rangeR)
	int *generateRandomArray(int n, int rangeL,int rangeR){
		
		assert(rangeL <= rangeR);  // 断言
		
		int* arr = new int[n];
		// 设置随机数生成器的种子 
		srand(time(NULL));
		for(int i = 0; i < n; i++)
		{
			//CC:获取 余数 一定在  特定范围内 (L,R)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		
		return arr;
	}
	
	
	//打印 arr数组 的所有内容
	template<typename T>
	void printArray(T arr[],int n){
		
		for(int i = 0; i < n; i++){
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		
		return;
	}
};


#endif  //INC_03_SELECTION_SORT_GENERATE_TEST_CASE_SORTTESTHELPER_H
