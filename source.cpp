#include "sort.h"
#include <stdio.h> 
#include <iostream>
using namespace std;   
#include <stdlib.h>   
#include <time.h>


 

void insertSort(int *a,int n){
	int i,j;
	
	clock_t start=clock(); 
	for(i=2;i<n;i++){
		if(a[i]<a[i-1])
		{
			a[0]=a[i];
			for(j=i-1;a[j]>a[0];j--)
				a[j+1]=a[j];
			a[j+1]=a[0]; 
		}
	} 
	
	
}
//分+合 
void MergeSort(int *a,int begin,int end,int *temp){
	int m;
	int tr2[end+1];
	if(begin=end){
		temp[begin]=a[begin];
	}else
	{
		m=(begin+end)/2;
		MergeSort(a,begin,m,tr2);
		MergeSort(a,m+1,end,tr2); 
		MergeArray(a,begin,m,end,temp);
		
	}
}
//合 
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int j,k,l;
	for(j=mid+1,k=begin;begin<=mid&&j<=end;k++){
		if(a[begin]<temp[j])
			temp[k]=a[begin++];
		else
			temp[k]=a[j++] ;
	} 
	if(begin<=mid){
		for(l=0;l<mid-begin;l++)
			temp[k+l]=a[begin+l]; 
	}
	if(j<=end){
		for(l=0;l<end-1;l++)
			temp[k+l]=a[j+l];
	}
}
//获得枢轴 
int Partition(int *a, int begin, int end){
	int pivotkey;
	
	pivotkey=a[begin];
	while(begin<end){
		while(begin<end&&a[end]>=pivotkey)
			end--;
		swap(a[begin],a[end]);
		while(begin<end&&a[begin]<=pivotkey)
			begin++;
		swap(a[begin],a[end]);
		
	}
	return begin;
} 
//快速排序 
void QuickSort_Recursion(int *a, int begin, int end){
	int pivot;
	if(begin<end)
	{
		pivot=Partition(a,begin,end);//轴 
		QuickSort_Recursion( a,begin,pivot-1);//低于轴 
		QuickSort_Recursion(a,pivot+1,end);//高于轴 
	}
} 
//优化的快速排序 ：轴，不必要的交换 
int Partition_2(int *a, int begin, int end){

	int pivotkey;

	int m = begin+ (end - begin) / 2; /* 计算数组中间的元素的下标 */  
	if (a[begin]>a[end])			
		swap(a[begin],a[end]);	/* 交换左端与右端数据，保证左端较小 */
	if (a[m]>a[end])
		swap(a[end],a[m]);		/* 交换中间与右端数据，保证中间较小 */
	if (a[m]>a[begin])
		swap(a[m],a[begin]);		/* 交换中间与左端数据，保证左端较小 */
	
	pivotkey=a[begin]; /* 用子表的第一个记录作枢轴记录 */
	a[0]=pivotkey;  /* 将枢轴关键字备份到L->r[0] */
	while(begin<end) /*  从表的两端交替地向中间扫描 */
	{ 
		 while(begin<end&&a[end]>=pivotkey)
			end--;
		 a[begin]=a[end];
		 while(begin<end&&a[begin]<=pivotkey)
			begin++;
		 a[end]=a[begin];
	}
	a[begin]=a[0];
	return begin; /* 返回枢轴所在位置 */
}
//优化快速排序：尾递归 
void QuickSort(int *a,int begin, int end){
	int pivot;
	if((end-begin)>MINN_QICKSORT){
		
		while(begin<end){
			pivot=Partition_2(a,begin,end);//轴 
			QuickSort(a,begin,pivot-1);
			end=pivot-1;
			
		}
	}
	else{
	insertSort(a,end);//数比较少时用插入更好、快	
	} 
} 



//计数排序
void CountSort(int *a,int len)
{
	
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[1], min = a[1];
	for (int i = 0; i < len; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (int i = 0; i < len; i++){
		//负数的处理 
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据，负数 
			a[j++] = i + min;
		}
	}
	//释放临时数组
	free(b);
	b = NULL;
}


 


 

 
// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num,int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;
    
	return (num / temp) % 10;
}
 
 
//基数排序  
void RadixCountSort(int *a,int size)
{
	int *radixArrays[10];    //分别为0~9的序列空间
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
	}
	
	for (int pos = 1; pos <=2; pos++)    //从个位开始到十位
	{
		for (int i = 1; i <=size; i++)    //分配过程
		{
			int num = GetNumInPos(a[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
        
		for (int i = 0, j =0; i < 10; i++)    //收集
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;    //复位
		}
	}
}
 

