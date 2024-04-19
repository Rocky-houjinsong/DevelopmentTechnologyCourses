#include <iostream>
#include <algorithm>

using namespace std;


// 提供 数组, 数组长度, 找到其中的最小值

/**
 * @brief 双重 for 暴力循环 -  从 数组入手,  先排序 后找元素
 * 若 后续业务无 排序相关需求, 则 性能浪费严重 
 * 
 * 改变 原有数组顺序;
 * 时间效率低, 数据大,则 浪费时间更多 - 算法一般 
 * @param arr 
 * @param n 
 */
void selectionSort(int arr[], int n){
	
	for(int i = 0; i < n; i++){
		//define min
		int minlndex = i;
		
		for(int j = i + 1; j < n; j++){
		// find min in [j,n) 
			if(arr[j] < arr[minlndex]){
				minlndex = j;
			}
		}
		
		// Insert element to Sorted List
		std::swap(arr[i], arr[minlndex]);
	}
}


/**
 * @brief  直接从 元素入手 , 找到 符合特定条件的元素 
 * 
 * 一层 for 循环解决,  算法效率高 
 * @param arr 
 * @param n 
 */
int selectionSortByPointer(int arr[], int n){
	// 定义两个指针,快慢指针 
	int fastPointer = 0;    // 下标 ,范围是 [0,n)
	int slowPointer = 0;  // 指向最小元素的下标
	for( fastPointer = 0; fastPointer < n; fastPointer++){
		if(arr[slowPointer] > arr[fastPointer]){
			slowPointer = fastPointer;
		}
	}
	
	return slowPointer;    //   arr[slowPointer] 值是多少 ? 

}

int main()
{
	int a[10] = {10,9,8,19,6,5,4,3,2,1};
	
	selectionSort(a,10); 
	
	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	
	cout << endl;  // a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	
	
	int b[10] = {10,9,18,19,6,335,4,3,2,1};
	
	cout << b[selectionSortByPointer(b, 10)] << endl;
	return 0;
}

/*
题目类型是 排序算法,  针对数据类型  来找出 合适的 算法思路 ,
针对  问题数据  来设计合适的 数据结构 



*/
