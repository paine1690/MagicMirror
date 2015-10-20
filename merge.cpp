#include<iostream>
#include <malloc.h> 
using namespace std;

void print(int a[], int n, int i)
{
	cout<<i<<":";
	for(int j=0; j<i; j++){
		cout<<a[j]<<" ";
	}
	cout<<endl;
}

void MergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;
	int j = mid + 1;
	int k = first;
	
	while(i<=mid && j<=last){
		if(a[i] > a[j]){
			temp[k++] = a[j++];
		}
		else{
			temp[k++] = a[i++];
		}
	}	
	while(i<=mid){
		temp[k++] = a[i++];
	}
	
	while(j<=last){
		temp[k++] = a[j++];
	}
}

void MergeStep(int a[], int step, int len, int temp[])//根据步长将len长度的 
{
	int first, mid, last;
	first = 0;
	last =  first + step + step -1;
	cout<<"+"<<last<<endl;
	mid = first + step -1;
	
	while(last<len){
		MergeArray(a, first, mid, last, temp);
		first = last +1;
		last = first + step + step - 1;
		mid = first + step -1; 
	}
	
	if(mid>len){//剩余元素已经有序 
		for(int i=first; i<len; i++){
			cout<<"i:"<<i<<endl;
			temp[i] = a[i];
		}
	}
	else{//mid到len-1无序 所以要从first到len-1 
		MergeArray(a, first, mid, len-1, temp);
	}
	
	print(temp, 14, 14);
}


void MergeSort(int a[], int len)
{
	int flag = 0;//
	//int *temp = (int*) malloc(len * sizeof(int));
	int *temp = new int[len];	 
	
	for(int step=1; step<len; step=step<<1){
		if(flag++ %2){//
			cout<<"step:"<<step<<endl;
			MergeStep(temp, step, len, a);
		}
		else{//
			cout<<"step:"<<step<<endl;
			MergeStep(a, step, len, temp);
		}
	}
	if(flag % 2){
		for(int i=0; i<len; i++){
			a[i] = temp[i];
		}
	}
	//free(temp);
	delete [] temp;
}	


int main()
{
	int arr[14] = { 213, 67, 89, 10, 23, 9, 23, 45, 12, 456, 234, 67, 12, 0 };  
	print(arr, 14, 14);
	MergeSort(arr, 14);
	print(arr, 14, 14);
	
} 
