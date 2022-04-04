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
//��+�� 
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
//�� 
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
//������� 
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
//�������� 
void QuickSort_Recursion(int *a, int begin, int end){
	int pivot;
	if(begin<end)
	{
		pivot=Partition(a,begin,end);//�� 
		QuickSort_Recursion( a,begin,pivot-1);//������ 
		QuickSort_Recursion(a,pivot+1,end);//������ 
	}
} 
//�Ż��Ŀ������� ���ᣬ����Ҫ�Ľ��� 
int Partition_2(int *a, int begin, int end){

	int pivotkey;

	int m = begin+ (end - begin) / 2; /* ���������м��Ԫ�ص��±� */  
	if (a[begin]>a[end])			
		swap(a[begin],a[end]);	/* ����������Ҷ����ݣ���֤��˽�С */
	if (a[m]>a[end])
		swap(a[end],a[m]);		/* �����м����Ҷ����ݣ���֤�м��С */
	if (a[m]>a[begin])
		swap(a[m],a[begin]);		/* �����м���������ݣ���֤��˽�С */
	
	pivotkey=a[begin]; /* ���ӱ�ĵ�һ����¼�������¼ */
	a[0]=pivotkey;  /* ������ؼ��ֱ��ݵ�L->r[0] */
	while(begin<end) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(begin<end&&a[end]>=pivotkey)
			end--;
		 a[begin]=a[end];
		 while(begin<end&&a[begin]<=pivotkey)
			begin++;
		 a[end]=a[begin];
	}
	a[begin]=a[0];
	return begin; /* ������������λ�� */
}
//�Ż���������β�ݹ� 
void QuickSort(int *a,int begin, int end){
	int pivot;
	if((end-begin)>MINN_QICKSORT){
		
		while(begin<end){
			pivot=Partition_2(a,begin,end);//�� 
			QuickSort(a,begin,pivot-1);
			end=pivot-1;
			
		}
	}
	else{
	insertSort(a,end);//���Ƚ���ʱ�ò�����á���	
	} 
} 



//��������
void CountSort(int *a,int len)
{
	
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max = a[1], min = a[1];
	for (int i = 0; i < len; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (int i = 0; i < len; i++){
		//�����Ĵ��� 
		b[a[i] - min] += 1;
	}
	int j = 0;
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ���ݣ����� 
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;
}


 


 

 
// �ҵ�num�Ĵӵ͵��ߵĵ�posλ������
int GetNumInPos(int num,int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;
    
	return (num / temp) % 10;
}
 
 
//��������  
void RadixCountSort(int *a,int size)
{
	int *radixArrays[10];    //�ֱ�Ϊ0~9�����пռ�
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
	}
	
	for (int pos = 1; pos <=2; pos++)    //�Ӹ�λ��ʼ��ʮλ
	{
		for (int i = 1; i <=size; i++)    //�������
		{
			int num = GetNumInPos(a[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
        
		for (int i = 0, j =0; i < 10; i++)    //�ռ�
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;    //��λ
		}
	}
}
 

