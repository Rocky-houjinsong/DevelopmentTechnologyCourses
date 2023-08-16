// 203 单链表 移除链表元素  无头结点(虚拟节点)
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
	int val ; 										//节点的数据域
	ListNode *next;         						//节点的指针域
	ListNode() :val(0),next(nullptr){}				//构造函数
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		// 删除头结点
		while (head != NULL && head->val == val) { // 注意这里不是if
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		
		// 删除非头结点
		ListNode* cur = head;
		while (cur != NULL && cur->next!= NULL) {
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			} else {
				cur = cur->next;
			}
		}
		return head;
	}
	ListNode* createLinkedList(int arr[], int n){
		
		if( n == 0 )
			return NULL;
		
		ListNode* head = new ListNode(arr[0]);
		ListNode* curNode = head;
		for( int i = 1 ; i < n ; i ++ ){
			curNode->next = new ListNode(arr[i]);
			curNode = curNode->next;
		}
		
		return head;
	}
	
	void printLinkedList(ListNode* head){
		
		ListNode* curNode = head;
		while( curNode != NULL ){
			cout << curNode->val << " -> ";
			curNode = curNode->next;
		}
		
		cout<<"NULL"<<endl;
		
		return;
	}
};

int main(void)
{
	
	int arr[] = {1,2,6,6,3,5,4,7,6};
	int n = sizeof(arr) /sizeof(int);
	Solution solution = Solution();
	ListNode* head = solution.createLinkedList(arr,n);
	solution.printLinkedList(head);
	solution.removeElements(head,6);
	solution.printLinkedList(head);
	return 0;
}

