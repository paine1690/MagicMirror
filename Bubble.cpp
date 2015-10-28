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

void bubbleSort(int a[], int n)
{
	int temp;
	for(int i=1; i<n-1; i++){
		for(int j=0; j<n-i; j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
//改进冒泡法 
void bubbleSort2(int a[], int n)
{
	int didswitch = 1;
	int firstchange = 1;
	int lastchange = n - 1;
	int i;
	
	while(didswitch){
		didswitch = 0;
		
		for(i=firstchange-1; i<lastchange; i++){
			if(a[i] > a[i+1]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				if(!didswitch){//第一次数据移动 
					firstchange = i;
				}
				didswitch = 1;
			} 
		}
		lastchange = i;
		if(firstchange<1){
			firstchange = 1;
		}
	}
	
}



int main()
{
	int a[6] = {6,7,7,8,45,9};
	bubbleSort2(a,6);
	print(a,6);
}
