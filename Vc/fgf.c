#include<stdio.h>
void main()
{
	int x,y,z;
	x=2;
	y=3;
	z=max(x,y);
	printf("%d",z);
}
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
