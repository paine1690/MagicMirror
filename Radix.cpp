#include<iostream>
#include<malloc.h>
using namespace std;

void print(int a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//确定桶号 
int getdigit(int x, int d)
{
	int a[] = {1, 1, 10};
	return ((x / a[d]) % 10);
}

void msdradix_sort(int arr[],int begin,int end,int d)  
	{     
	const int radix = 10;   
	int count[radix], i, j; 
	//置空 
	for(i = 0; i < radix; ++i)   
	{
	    count[i] = 0;   
	}
	//分配桶存储空间
	int *bucket = (int *) malloc((end-begin+1) * sizeof(int));    
	//统计各桶需要装的元素的个数  
	for(i = begin;i <= end; ++i)   
	{
	    count[getdigit(arr[i], d)]++;   
	}
	//求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
	for(i = 1; i < radix; ++i)   
	{
	    count[i] = count[i] + count[i-1];    
	}
	//这里要从右向左扫描，保证排序稳定性 
	for(i = end;i >= begin; --i)          
	{    
	    j = getdigit(arr[i], d);      //求出关键码的第d位的数字， 例如：576的第3位是5   
	    bucket[count[j]-1] = arr[i];   //放入对应的桶中，count[j]-1是第j个桶的右边界索引   
	    --count[j];                    //第j个桶放下一个元素的位置(右边界索引+1)   
	}   
	//注意：此时count[i]为第i个桶左边界    
	//从各个桶中收集数据  
	for(i = begin, j = 0;i <= end; ++i, ++j)  
	{
	    arr[i] = bucket[j]; 
	}       
	//释放存储空间
	free(bucket);   
	//对各桶中数据进行再排序
	for(i = 0;i < radix; i++)  
	{   
	    int p1 = begin + count[i];         //第i个桶的左边界   
	    int p2 = begin + count[i+1]-1;     //第i个桶的右边界   
	    if(p1 < p2 && d > 1)  
	    {
	        msdradix_sort(arr, p1, p2, d-1);  //对第i个桶递归调用，进行基数排序，数位降 1    
	    }
	}  
} 


int main()
{
	int  a[] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89};
	int len = sizeof(a)/sizeof(int);
	print(a, len);
	msdradix_sort(a, 0, len-1, 2);
	print(a, len);
}










