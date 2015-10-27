#include<iostream>
#include <malloc.h> 
using namespace std;

void print(int a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

/****************************************** 
         筛选法建最大堆 O(n) 
         
 *从length/2开始调整，直至跟节点 
 *比较i的左右孩子，依次向下调整直至最低层 
*******************************************/
void HeapBuid(int a[], int length)
{
	for(int i=length/2; i>=0; i--){
		int left=2*i;
		int right=2*i+1;
		int max=i;
		
		while(left<length){
			if(a[left]>a[i]){
				max = left;
			}
			if(right<length && a[right]>a[max]){
				max = right;
			}
			if(max != i){
				int temp = a[i];
				a[i] = a[max];
				a[max] = temp;
				i = max;
				left = 2*i;
				right = 2*i+1; 
			}
			else{
				break;
			}
		} 
	}
}
/***********筛选法建堆*************/


/****************************************** 
         插入法建最大堆 O(nlogn) 
         
	*i从第二个开始，依次向后比较
	*若大于父节点，则向上调整，直至根节点 
*******************************************/
void HeapBuid2(int a[], int length)
{
	for(int i=2; i<length; i++){
		int father=i/2;
		while(father>=0){
			if(a[i]>a[father]){
				int temp = a[i];
				a[i] = a[father];
				a[father] = temp;
				i = father;
				father = i/2;
			}
			else{
				break;
			}
		}
	}	
} 
/***********插入法建堆*************/


//堆排序
void HeapSort(int a[], int length)
{
	while(length>1){
		HeapBuid(a, length);
		int temp = a[length-1];
		a[length-1] = a[0];
		a[0] = temp;
		length -= 1;		
	}
}


int main()
{
	int a[6] = {67,9,4,76,3,8};
	HeapSort(a,6);
	print(a, 6);
}
