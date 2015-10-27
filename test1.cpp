#include<iostream>
using namespace std;



void print(int a[], int n)
{
	cout<<"a:";
	for(int j=0; j<n; j++){
		cout<<a[j]<<" ";
	}
	cout<<endl;
}


int main()
{
	int a[4] = {2,4,8,3};
	int b[6] = {8,56,1,3,7};
	print(b, 6);
}
