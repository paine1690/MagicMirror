#include <iostream>
using namespace std;

void print(int a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//1¡¢²åÈëÅÅÐò 
void insertSort(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		if(a[i] < a[i-1])
		{ 
			int j = i-1;
			int x = a[i];
			a[i] = a[i-1];
			while(j>0 && x<a[j-1])
			{
				a[j] = a[j-1];
				j--;
			}
			a[j] = x;
		}
	}
}

//2¡¢Ï£¶ûÅÅÐò 
void shellInsertSort(int a[], int n, int dk)
{
	for(int i=dk; i<=n; i++)
	{	
		if(a[i] < a[i-dk])
		{
			int j = i - dk;
			int x = a[i];
			a[i] = a[i-dk];
			while(j>=dk && x<a[j-dk])
			{
				a[j] = a[j-dk];
				j -= dk;	
			}	
			a[j] = x;
		}
	}	
} 

void shellSort(int a[], int n)
{
	int dk = n/2;
	while(dk>=1){
		shellInsertSort(a,n,dk);
		dk = dk/2;
	}
	
}

int main()
{
	int a[7] = {6,17,7,8,45,9,6};
	insertSort(a, 7);
	//shellSort(a, 6);
	print(a,7);
}
