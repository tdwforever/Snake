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
	printf("请输入一个大于1990年一月一日的日期(中间用空格隔开)：\n");
	scanf("%d %d %d",&y,&m,&d);
	if((y%4!=0||y%100==0)&&m==2&&d>=29)
	{   printf("日期输入有错误\n");
	if((y<1990||m<0||m>12||d<0||d>31)||(m==2,d>28))
	   printf("日期输入有错误\n");
	}
}
int total()
{
	int i,y,m,d,j,t,k,l,sum,s;
	j=0;
	s=0;
	if(y<1990||m<0||m>12||d<0||d>31)
		printf("日期输入有错误\n");
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
		printf("这天是晒网\n");
	else
		printf("这天是打鱼\n");
	printf("%d",sum);
}
