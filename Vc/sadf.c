#include "stdio.h"
#define By 1990
#define Bm 1
#define Bd 1
int main()
{
	judge();
	total();
}
int judge()
{
	int y,m,d; 
	printf("������һ������1990��һ��һ�յ�����(�м��ÿո����)��\n");
	scanf("%d %d %d",&y,&m,&d);
	if((y%4!=0||y%100==0)&&m==2&&d>=29)
	{   printf("���������д���\n");
	if((y<1990||m<0||m>12||d<0||d>31)||(m==2,d>28))
	   printf("���������д���\n");
	}
}
int total()
{
	int i,y,m,d,j,t,k,l,sum,s;
	j=0;
	s=0;
	if(y<1990||m<0||m>12||d<0||d>31)
		printf("���������д���\n");
	for(i=1990;i<=y;i++)
	{   
		if(i%4==0&&i%100!=0)
			j++;
	}
	for(l=1;l<m;l++)
	{
		if(l==1||l==3||l==5||l==7||l==8||l==12||l==10)
		    t=31;
	    else 
		    t=30;
		s=s+t;
	}
	sum=j*366+(y-By-j)*365+s+d-Bd-1;
	if(sum%5==0||sum%5==4)
		printf("������ɹ��\n");
	else
		printf("�����Ǵ���\n");
	printf("%d",sum);
}
