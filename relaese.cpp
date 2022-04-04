#include "sort.h" 
#include <stdio.h> 
#include "stdlib.h"
#include <time.h>
#include <windows.h> 

int main(){
	int first;
	int sec=1;
	int num; 
	int i;
	int n;
	clock_t start;
	clock_t diff;
	while(sec) {
		printf("�������\n");
		printf("Enter 0: �ڲ�ͬ�Ĵ��������µ���ʱ����������Σ�10000��50000��200000��\n");
		printf("Enter 1: �ڴ���С�������µ�������ʱ������100������*100k������\n");
		printf("Enter 3:�˳�ϵͳ\n");
		scanf("%d",&first);
	//�������� 
		if(first==0){
			
			int flag=1;
			while(flag){
				printf("���ݲ��\n");
				printf("Enter 0: 10000\n");
				printf("Enter 1: 50000\n");
				printf("Enter 2: 200000\n");
				printf("Enter 3���˳�\n");
				printf("������:");
				scanf("%d",&num);
			
				switch(num){
					case 0:  n=10000;
							int a[10001];
							a[0]=0;//�ڱ� 							
							srand(time(0));
							FILE*f;
							f=fopen("test.txt","a");
							
							for (i=1;i<=n;i++){
								a[i]=rand()%100;
								fwrite(&a[i],sizeof(int),1,f);
								 
							}
							printf("������10000�� [0,99)����\n");
							fclose(f);
							
							start=clock();
							insertSort(a,n);
							diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							start=clock(); 
							MergeSort(a,1,n,a);
							diff =clock()-start;
							printf("�鲢������ʱ:%d\n",diff);
							
							
							start=clock();
							QuickSort_Recursion(a, 1,n);
							diff =clock()-start;
							printf("�������򣨵ݹ飩��ʱ:%d\n",diff);
														
							start=clock();
							QuickSort(a,1, n);
							diff =clock()-start;
							printf("���������Ż��棩��ʱ:%d\n",diff);
														
							 start=clock();
							CountSort(a,n );
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							 start=clock();
							RadixCountSort(a,n);
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							
							break;
					case 1: 
							n=50000;
							int b[50001];
							b[0]=0;//�ڱ� 							
							srand(time(0));
							
							f=fopen("test.txt","a");
							
							for (i=1;i<=n;i++){
								b[i]=rand()%100;
								fwrite(&b[i],sizeof(int),1,f);
								
							}
							printf("������50000�� [0,99)����\n"); 
							fclose(f);
							
							start=clock();
							insertSort(a,n);
							diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							 start=clock(); 
							MergeSort(b,1,n,b);
							 diff =clock()-start;
							printf("�鲢������ʱ:%d\n",diff);
							
							
							 start=clock();
							QuickSort_Recursion(b, 1,n);
							 diff =clock()-start;
							printf("�������򣨵ݹ飩��ʱ:%d\n",diff);
														
							 start=clock();
							QuickSort(b,1, n);
							 diff =clock()-start;
							printf("���������Ż��棩��ʱ:%d\n",diff);
														
							 start=clock();
							CountSort(b ,n);
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							 start=clock();
							RadixCountSort(b,n);
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);							
							break;
					case 2: 
							n=200000;
							int c[200001];
							c[0]=0;//�ڱ� 							
							srand(time(0));
							
							f=fopen("test.txt","a");
							
							for (i=1;i<=n;i++){
								c[i]=rand()%100;
								fwrite(&c[i],sizeof(int),1,f);
								
							}
							printf("������200000�� [0,99)����\n"); 
							fclose(f);
							
							start=clock();
							insertSort(a,n);
							diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							 start=clock(); 
							MergeSort(c,1,n,c);
							 diff =clock()-start;
							printf("�鲢������ʱ:%d\n",diff);
							
							
							 start=clock();
							QuickSort_Recursion(c, 1,n);
							 diff =clock()-start;
							printf("�������򣨵ݹ飩��ʱ:%d\n",diff);
														
							 start=clock();
							QuickSort(c,1, n);
							 diff =clock()-start;
							printf("���������Ż��棩��ʱ:%d\n",diff);
														
							 start=clock();
							CountSort(c ,n);
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							 start=clock();
							RadixCountSort(c,n);
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
							
							break;
					case 3: flag=0;
							break;
						
					default: printf("��Ч���֣�����������\n");
							system("pause");
							system("cls");
					}
			}
		
		}//����Ա 
		else if(first==1){
			
				n=100;
				int a[n+1];
				a[0]=0;//�ڱ� 							
				srand(time(0));
				FILE*f;
				f=fopen("test.txt","a");
							
				for (i=1;i<=n;i++){
					a[i]=rand()%100;
					fwrite(&a[i],sizeof(int),1,f);
					 
				}
				printf("������100�� [0,99)����\n");
				fclose(f);
				int snum;					
				int ssflag=1;
				while(ssflag){
					printf("���д���\n");
					printf("Enter 0: 100������*100\n");
					printf("Enter 1:  100������*1000\n");
					printf("Enter 2:  100������*10000\n");
					printf("Enter 3: �˳�ϵͳ\n");					
					scanf("%d",&snum);
					
								
					switch(snum){						
					case 0: 
							
							
							start=clock();
							for(i=0;i<100;i++){
							
							insertSort(a,n);
							}
							diff =clock()-start;
							printf("����������ʱ:%d ",diff);
							
							 start=clock(); 
							 for(i=0;i<100;i++){
							MergeSort(a,1,n,a);
							}
							 diff =clock()-start;
							printf("�鲢������ʱ:%d  ",diff);
							
							
							 start=clock();
							 for(i=0;i<100;i++){
							QuickSort_Recursion(a, 1,n);
							}
							 diff =clock()-start;
							printf("�������򣨵ݹ飩��ʱ:%d  ",diff);
														
							 start=clock();
							 for(i=0;i<100;i++){
							QuickSort(a,1, n);
							}
							 diff =clock()-start;
							printf("���������Ż��棩��ʱ:%d  ",diff);
														
							 start=clock();
							 for(i=0;i<100;i++){
							CountSort(a ,n);
							}
							 diff =clock()-start;
							printf("����������ʱ:%d  ",diff);
							
							 start=clock();
							 for(i=0;i<100;i++){
							RadixCountSort(a,n);
							}
							 diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
						
								
							
							break;
					case 1:  
							start=clock();
							for(i=0;i<1000;i++){
							
							insertSort(a,n);
							}
						diff =clock()-start;
						printf("����������ʱ:%d ",diff);
						
							 start=clock();
							 for(i=0;i<1000;i++){ 
							MergeSort(a,1,n,a);
							}
							diff =clock()-start;
							printf("�鲢������ʱ:%d  ",diff);
							
							
							start=clock();
							for(i=0;i<1000;i++){
							QuickSort_Recursion(a, 1,n);
							}
							diff =clock()-start;
							printf("�������򣨵ݹ飩��ʱ:%d  ",diff);
														
							start=clock();
							for(i=0;i<1000;i++){
							QuickSort(a,1, n);
							}
							diff =clock()-start;
							printf("���������Ż��棩��ʱ:%d   ",diff);
														
						start=clock();
						for(i=0;i<1000;i++){
							CountSort(a ,n);
							}
							 diff =clock()-start;
							printf("����������ʱ:%d  ",diff);
							
							 start=clock();
							 for(i=0;i<1000;i++){
							RadixCountSort(a,n);
							}
							diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
						
								
							
							break;
					case 2: 
							start=clock();
							for(i=0;i<10000;i++){
							
							insertSort(a,n);
							}
							diff =clock()-start;
							printf("����������ʱ:%d ",diff);
							
							start=clock(); 
							for(i=0;i<10000;i++){
							MergeSort(a,1,n,a);
							}
							diff =clock()-start;
							printf("�鲢������ʱ:%d  ",diff);
							
							
							start=clock();
							for(i=0;i<10000;i++){
							QuickSort_Recursion(a, 1,n);
							}
							diff =clock()-start;
							printf("�������򣨵ݹ飩��ʱ:%d  ",diff);
														
							 start=clock();
							 for(i=0;i<10000;i++){
							QuickSort(a,1, n);
							}
							diff =clock()-start;
							printf("���������Ż��棩��ʱ:%d  ",diff);
														
							start=clock();
							for(i=0;i<10000;i++){
							CountSort(a ,n);
							}
							diff =clock()-start;
							printf("����������ʱ:%d  ",diff);
							
							start=clock();
							for(i=0;i<10000;i++){
							RadixCountSort(a,n);
							}
							diff =clock()-start;
							printf("����������ʱ:%d\n",diff);
							
						
								
							
							break;
					case 3: ssflag=0;
							break;							
					default:printf("��Ч���֣�����������\n");
							system("pause");
							system("cls");
					}		
				}
		
			}else if(first==3){
					sec=0;
					system("cls"); 
				}else{
					printf("��Ч���֣�����������\n");
					system("pause");
					system("cls");
					
				} 
}
	return 0; 
}
