#include<iostream>
using namespace std;
/************* 
¹é²¢£¬Î´¸Ä½ø 
*************/
void print(int a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
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
	
	for(int i=0; i<k; i++){
		a[first+i]=temp[first+i];
	}
}

void mergeSort(int a[], int first, int last, int temp[])
{
	if(first<last){
		int mid=(first+last)/2;
		mergeSort(a,first,mid,temp);
		mergeSort(a,mid+1,last,temp);
		mergeArray(a,first,mid,last,temp);
	}
}




int main()
{
	int a[6] = {6,9,4,67,32,87};
	int temp[6];
	print(a, 6);
	mergeSort(a,0,5,temp);
	print(a,6);
}
