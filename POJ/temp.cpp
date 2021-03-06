#include<stdio.h>
#include<iostream>
using namespace std;

#define maxN 25
int map[maxN][maxN];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int x2,y2,n,m;

int dfs(int x,int y,int step)
{
	if(step>10)return step;
	int minstep=11;
	for(int i=0;i<4;i++)
		for(int k=1;k<20;k++)
		{
			int x1=x+dir[i][0]*k;
			int y1=y+dir[i][1]*k;
			if(x1>0&&x1<=m&&y1>0&&y1<=n)
			{
				if(map[y1][x1]==3)return step+1;
				else if(map[y1][x1]==1)
				{
					if(k==1)break;
					int x2=x+dir[i][0]*(k-1);
					int y2=y+dir[i][1]*(k-1);
					map[y1][x1]=0;
					minstep=min(minstep,dfs(x2,y2,step+1));
					map[y1][x1]=1;
					break;
				}
			}
			else
				break;
		}
	return minstep;
}

int main()
{
	while(scanf("%d%d",&m,&n)&&n&&m)
	{
		memset(map,0,sizeof(map));
		int x1,y1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
					x1=i,y1=j;
			}
		int step=dfs(x1,y1,0);
		if(step<11)
			printf("%d\n",step);
		else
			printf("-1\n");
	}
}
