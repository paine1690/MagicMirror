#include<iostream>
using namespace std;

void print(int a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i=first;
	int j=mid+1;
	int k=first;
	while(i<=mid && j<=last){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	
	while(i<=mid){
		temp[k++]=a[i++];
	}
	
	while(j<=last){
		temp[k++]=a[j++];
	}
}





int main()
{
	int a[6] = {6,9,4,67,32,87};
	print(a, 6);
}
