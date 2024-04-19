#include <iostream>
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){
	
	for(int i = 0; i < n; i++){
		//TODO		
		int minIndex = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		
		std::swap(arr[i],arr[minIndex]);
	}
}



int main(){
	// 测试模板函数, 传入整形数组
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(a,10);
	for(int i = 0; i < 10; i++){
		std::cout << a[i] << " ";
		}
	
	std::cout << endl;
	
	float b[4] = {4.4,3.3,2.2,1.1};
	selectionSort(b,4);
	for(int i = 0; i < 4; i++){
		std::cout << b[i] << " ";
	}
	
	std::cout << endl;
	
	string c[4] = {"D","C","B","A"};
	selectionSort(c,4);
	for(int i = 0; i < 4; i++){
		std::cout << c[i] << " ";
	}
	
	std::cout << endl;
	
	Student d[4] = {{"D",90}, {"C",100},{"B",95},{"A",95}};
	selectionSort(d,4);
	for(int i = 0; i < 4; i++){
		std::cout << d[i] << " ";
	}
	
	std::cout << endl;
	
	return 0;
	
}
