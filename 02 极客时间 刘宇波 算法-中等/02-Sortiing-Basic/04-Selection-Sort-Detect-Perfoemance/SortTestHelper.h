#ifndef INC_03_SELECT_SORT_DELECT_PERFORMANCE_SORTTESTHELPER_H
#define INC_03_SELECT_SORT_DELECT_PERFORMANCE_SORTTESTHELPER_H

#include <iostream>
#include <ctime>   // Clock_t 需要
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper{
	
	// generate
	int* generateRandomArray(int n,int rangeL,int rangeR){
		assert(rangeL <= rangeR);
		
		int* arr = new int[n];
		
		srand(time(NULL));
		
		for(int i = 0; i < n; i++){
			//TODO
			arr[i] = rand() %(rangeR - rangeL + 1) + rangeL;
		}
		
		return arr;
	}
	
	
	
	// print the all content of arr
	template<typename T>
	void printArray(T arr[], int n){
		for(int i = 0; i < n; i++){
			//TODO
			std::cout << arr[i] <<  " ";
		}
		
		std::cout << std::endl;
	}
	
	//detemine whether the array is ordered 
	// 递增 true
	template<typename T>
	bool isSorted(T arr[], int n){
		for(int i = 0; i < n - 1; i++){
			if(arr[i] > arr[i + 1]){
				return false;
			}
		}
		
		return true;
	}
	
	// test
	template<typename T>
	void testSort(const string& sortName, void(* sort)(T[], int), T arr[] ,int n){
		clock_t startTime = clock(); // 度量 CPU执行时间的数据类型 ; 用于 计算程序的执行时间; 获取 当前时钟周期数
		sort(arr,n);
		clock_t endTime = clock();
		
		assert(isSorted(arr,n));
		
		std::cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
		
		return ;
		
		
	}
	
}

#endif INC_03_SELECT_SORT_DELECT_PERFORMANCE_SORTTESTHELPER_H
