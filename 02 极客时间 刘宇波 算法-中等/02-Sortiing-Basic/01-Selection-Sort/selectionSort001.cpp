#include <iostream>
#include <algorithm>

using namespace std;


// 提供 数组, 数组长度, 找到其中的最小值
// 假定 第一个最小,后续通过验证 确定最小  , 每次循环确定最小值, 排列 ; 
// 实现 排序 
void selectionSort(int arr[], int n){
	
	for(int i = 0; i < n; i++){
		// find min in [i,n)
		int minlndex = i;
		
		for(int j = i + 1; j < n; j++){
			//define min
			if(arr[j] < arr[minlndex]){
				minlndex = j;
			}
		}
		
		
		std::swap(arr[i], arr[minlndex]);
	}
}


int main()
{
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(a,10);
	
	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	
	cout << endl;
	// a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	return 0;
}
