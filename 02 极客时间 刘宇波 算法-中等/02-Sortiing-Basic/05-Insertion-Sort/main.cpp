#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
	for(int i = 1; i < n; i++){
		//寻找元素arr[i] 合适的 插入位置
		// Method 1
		for(int j = i; j > 0; j--){
			if(arr[j] < arr[j -1]){
				swap(arr[j], arr[j - 1]);
			}else{
				break;
			}
		}
		
		// Method 2
//		for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
//			swap(arr[j], arr[j - 1]);
//		}
		
	}
	
	return ;
}


int main(){
	
	int n = 20000;
	
	std::cout << "Test for random array, size = "<< n << ", random range[0,"<< n << "]" << std::endl;
	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::copyIntArray(arr1,n);
	
	SortTestHelper::testSort("Insertion Sort",insertionSort, arr1, n);
	SortTestHelper::testSort("Selection Sort",selectionSort, arr2, n);
	
	delete[] arr1;
	delete[] arr2;
	
	std::cout << std::endl;
	
	return 0;
}
