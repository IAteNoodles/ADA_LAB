#include <stdio.h>
void main()
{
int cur_w,n;
float tot_v;
int p[10],w[10],W;
int i, maxi;
int used[10];
printf("Enter the no. of items:\n");
scanf("%d",&n);
printf("Enter the weight and price of all items:\n");
for(i=0;i<n;i++)
{
scanf("%d%d",&w[i],&p[i]);
}
printf("Enter the capacity of knapsack:\n");
scanf("%d",&W);
for (i = 0; i < n; ++i)
used[i] = 0;
cur_w = W;
while (cur_w > 0)
{
maxi = -1;
for (i = 0; i < n; ++i)
if ((used[i] == 0) && ((maxi == -1) || ((float)w[i]/p[i] >
(float)w[maxi]/p[maxi]))) maxi = i;
used[maxi] = 1;
cur_w -= p[maxi];
tot_v += w[maxi];
if (cur_w >= 0)
printf("Added object %d (%d, %d) completely in the bag. Space left:%d.\n",
maxi + 1, w[maxi], p[maxi], cur_w);
else
{
printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((1
+(float)cur_w/p[maxi]) * 100), w[maxi], p[maxi], maxi + 1);
tot_v -= w[maxi];
tot_v += (1 + (float)cur_w/p[maxi]) * w[maxi];
}
}
printf("Filled the bag with objects worth %.2f.\n", tot_v);
}