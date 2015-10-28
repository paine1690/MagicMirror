#include<iostream>
using namespace std;

void print(int a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void quikSort(int a[], int l, int r)
{
	if(l < r)
	{
		int i = l, j = r, x = a[l];
		while(i < j)
		{
			while(i<j && a[j]>x)//从右向左找第一个小于X的数 
			{
				j--;
			}
			if(i<j)
			{
				a[i++] = a[j];
			}
			
			while(i<j && a[i]<x)//从左向右找第一个大于X的数 
			{
				i++;
			}
			if(i<j)
			{
				a[j--] = a[i];
			}
		}
		a[i] = x;
		quikSort(a, l, i-1);
		quikSort(a, i+1, r);
	}
}

int main()
{
    int a[8] = {4,2,5,6,3,8,1,7};

    quikSort(a, 0, 8);
    print(a,8);

	
}
