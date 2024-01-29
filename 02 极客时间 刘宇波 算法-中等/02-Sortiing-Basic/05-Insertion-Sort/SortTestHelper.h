//Created by 01/15
#ifndef INC_05_INSERTION_SORT_SORTTESTHELPER_H
#define INC_05_INSERTION_SORT_SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
	// generate array
	int* generateRandomArray(int n, int rangeL, int rangeR){
		//assert(rangeL <= rangeR);
		
		int* arr = new int[n];
		
		srand(time(NULL));
		
		for(int i = 0; i < n; i++){
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		
		return arr;
	}
	
	
	//copy array
	
	int* copyIntArray(int a[], int n){
		int* arr = new int[n];
		//VS 中 copy函数 认为是不安全的;
		std::copy(a,a + n, arr);
		return arr;
	}
	
	// print the all content of array 
	
	template<typename T>
	void printArray(T arr[], int n){
		for(int i = 0; i < n; i++){
			std::cout << arr[i] <<  " ";
		}
		
		std::cout << std::endl;
		
		return ;
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
	
	// 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
	template<typename T>
	void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;
		
	//	assert(isSorted(arr, n));
		
		return;
	}
	
};






#endif INC_05_INSERTION_SORT_SORTTESTHELPER_H
