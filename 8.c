#include<stdio.h>
int s[10],d,n,set[10],count=0;
void display(int);
int flag=0;
int subset(int,int);
void main()
{
int i;
printf("Enter the number of elements in set\n");
scanf("%d",&n);
printf("Enter the set values\n");
for(i=0;i<n;++i)
scanf("%d",&s[i]);
printf("Enter the sum\n");
scanf("%d",&d);
printf("The program output is\n");
subset(0,0);
if(flag==0)
printf("There is no solution");
}
int subset(int sum,int i)
{
if(sum==d)
{
flag=1; display(count);
return (0);
}
if(sum>d||i>=n)
return 0;
else
{
set[count]=s[i];
count++;
subset(sum+s[i],i+1);
count--;
subset(sum,i+1);
}
}
void display(int count)
{
int i; printf("{");
for(i=0;i<count;i++)
printf("%d ",set[i]);
printf("}");
}