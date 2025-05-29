#include<stdio.h>
void readf();
void amin();
int cost[20][20],a[20][20];
int i,j,k,n;
void readf()
{
printf("\n Enter the number of vertices :");
scanf("%d",&n);
printf("\n Enter the weighted matrix - 999 for infinity:");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0 && (i!=j))
cost[i][j]=999;
a[i][j]=cost[i][j];
}
}
}
void amin()
{
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]>a[i][k]+a[k][j])
{
a[i][j]=a[i][k]+a[k][j];
}
}
}
}
printf("\n The All pair shortest path is:");
for(i=0;i<n;i++)
{
printf("\n"); for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
}
}
void main()
{
readf();
amin();
}