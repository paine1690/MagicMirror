#include<iostream>
using namespace std;


int SelectMinKey(int a[], int n, int i)
{
	int k = i;
	for(int j=i+1; j<n; j++)
	if(a[k]>a[j]){
		k=j;
	}
	return k;
}

void SelectSort(int a[], int n)
{
	int key, temp;
	for(int i=0; i<n; i++){
		key = SelectMinKey(a, n, i);
		if(key!=i){
			temp = a[i];
			a[i] = a[key];
			a[key] = temp;
		}
	}
}

//¸Ä½ø
void SelectSort_2(int a[], int n)
{
	int i, j, min, max, temp;
	for(i=1; i<=n/2; i++){
		min = i; 
		max = i;
		for(j=i+1; j<=n-i; j++){
			if(a[j]>a[max]){
				max = j;
				continue;
			}
			if(a[j]<a[min]){
				min = j;
			}
		}
		temp = a[i-1]; a[i-1] = a[min]; a[min] = temp;
		temp = a[n-i]; a[n-i] = a[max]; a[max] = temp;
		
	}
} 



int main()
{
	int a[8] = {3,1,5,7,2,4,9,6};  
	//SelectSort(a, 8);
	SelectSort_2(a, 8);
	for(int i=0; i<8; i++){
		cout<<a[i]<<" ";
	}
}










