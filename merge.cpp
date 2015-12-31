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


/************
改进，无回写 
************/
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
	
	mid = first + step -1;
	
	while(last<len){
		MergeArray(a, first, mid, last, temp);
		first = last +1;
		last = first + step + step - 1;
		mid = first + step -1; 
	}
	
	if(mid>len){//剩余元素已经有序 
		for(int i=first; i<len; i++){
			
			temp[i] = a[i];
		}
	}
	else{//mid到len-1无序 所以要从first到len-1 
		MergeArray(a, first, mid, len-1, temp);
	}
	

}


void MergeSort(int a[], int len, int temp[])
{
	int flag = 0;//
	//int *temp = (int*) malloc(len * sizeof(int));
	//int *temp = new int[len];	 

	for(int step=1; step<len; step=step<<1){
		if(flag++ %2){//
			MergeStep(temp, step, len, a);
		}
		else{//
			MergeStep(a, step, len, temp);
		}
	}
	if(flag % 2){
		for(int i=0; i<len; i++){
			a[i] = temp[i];
		}
	}

}	



/*********
求A-B并B-A 
*********/ 
void A_B(int a[], int m, int b[], int n, int c[])
{
	int i=0;
	int j=0;
	int k=0;
	while(i<m && j<n){
		if(a[i]<b[j]){
			c[k++] = a[i++];
		}
		else if(a[i]>b[j]){
			c[k++] = b[j++];
		}
		else{
			i++;
			j++;
		}
	}
	while(i<m){
		c[k++] = a[i++];
	}
	
	while(j<n){
		c[k++] = b[j++];
	}
	
}

/*****************
改进，无逆序子序列 
*****************/ 

void MergeStep2(int a[], int n, int b[], int j, int temp[])
{
	int first,mid,last,step;
	print(b,j,j);	
	cout<<"b[j]"<<b[j-1]<<endl;
	
	for(int step=1; step<n/2; step=step*2){
		first = 0;
		mid = step-1;
		last = mid+step;
		cout<<"last:"<<last<<endl;
		
		while(last<=j-1){
			cout<<"first"<<first<<"mid"<<b[mid]<<"last"<<b[last]<<endl;
			MergeArray(a, first, b[mid], b[last], temp);
			first = b[last] + 1;
			mid = last+step;
			last = mid+step;
			cout<<"first"<<first<<"mid"<<b[mid]<<"last"<<b[last]<<endl;
			cout<<"last::"<<last<<endl;
		} 
		if(mid<=j-1){
			MergeArray(a, first, b[mid], n-1, temp);
		}
		
		print(a,15,15);
	}
	print(a,15,15);
}

void MergeSort2(int a[], int n, int b[], int temp[])
{
	int j=0;
	for(int i=0; i<n-1; i++){
		if(a[i]>a[i+1]){
			b[j++]=i;
		}
	}
	print(b,j,j);	
	MergeStep2(a, n, b, j, temp);
} 




int main()
{
	int a[15] = {45,32,54,12,43,65,11,3,43,6,33,90,44,1,178};
	//int a[10] = { 10,2,3,4,5,6,9,8,7,1 };
	int b[15];
	int temp[15];
	MergeSort(a, 14, temp);
//	MergeSort(b, 5, temp);
//	A_B(a, 14, b, 5, c);
//	print(a, 14, 14);
//	print(b, 5, 5);
//	print(c, 17, 17);
	//MergeSort2(a, 15, b, temp);
	print(a,15,15);
} 


















