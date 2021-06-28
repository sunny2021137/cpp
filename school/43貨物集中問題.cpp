#include <iostream>
#include <algorithm>
using namespace std;

int choose(int co[],int n)
{
	int cost[n];
	int min;
	for(int i=0;i<n;i++)
	{
		cost[i]=0;
		for(int j=0;j<n;j++)
		{
			if(j==i)continue;
			else
			{
				cost[i]+=abs(j-i)*co[j];
			}
		}
		if(i==0||cost[i]<cost[min])min=i;
	}
	return min;
}
int cost(int x[],int y[],int minX,int minY,int r,int c)
{
	int cost=0;
	for(int i=0;i<r;i++)
		cost+=abs(i-minX)*x[i];
	for(int j=0;j<c;j++)
		cost+=abs(j-minY)*y[j]; 
	cost*=10;	
	return cost;
}
int main()
{
	int n,r,c;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>r>>c;
			int graph[r][c];
			int x[r],y[c];
			for(int j=0;j<r;j++)
				x[j]=0;
			for(int j=0;j<c;j++)
				y[j]=0;
				
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
				{
					cin>>graph[j][k];
					x[j]+=graph[j][k];
					y[k]+=graph[j][k];
				}
			int minX=choose(x,r),minY=choose(y,c);
			cout<<minX+1<<" "<<minY+1<<" ";
			cout<<cost(x,y,minX,minY,r,c)<<endl;
		}
	}	
} 
