#include<stdio.h>
#include<math.h>
void warshal(int p[10][10], int n)
{
int i, j, k;
for (k = 1; k <= n; k++)
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}
void main()
{
int p[10][10] = { 0 }, n, e, u, v, i, j;
printf("\n Enter the number of vertices:");
scanf("%d", &n);
printf("\n Enter the number of edges:");
scanf("%d", &e);
printf("Enter the edges: (u,v)\n");
for (i = 1; i <= e; i++)
{
scanf("%d%d", &u,&v);
p[u][v] = 1;
}
printf("\n Matrix of input data: \n");
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
printf("%d\t", p[i][j]);
printf("\n");
}
warshal(p, n);
printf("\n Transitive closure: \n");
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
printf("%d\t", p[i][j]);
printf("\n");
}
}