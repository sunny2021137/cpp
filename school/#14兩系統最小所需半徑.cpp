#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x[2],y[2],m;
		cin>>x[0]>>x[1];
		cin>>y[0]>>y[1];
		
		cin>>m;
		int p[m][2],min,cost,ry=0,l[m+1][2];
		l[m][0]=0;
		for(int i=0;i<m;i++)
		{
			cin>>p[i][0]>>p[i][1];
			l[i][0]=(p[i][0]-x[0])*(p[i][0]-x[0])+(p[i][1]-x[1])*(p[i][1]-x[1]);
			l[i][1]=(p[i][0]-y[0])*(p[i][0]-y[0])+(p[i][1]-y[1])*(p[i][1]-y[1]);
		}
		int temp;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m-1;j++)
			{
				if(l[j][0]<l[j+1][0])
				{
					temp=l[j][0];
					l[j][0]=l[j+1][0];
					l[j+1][0]=temp;
					temp=l[j][1];
					l[j][1]=l[j+1][1];
					l[j+1][1]=temp;
				}
			}
		}
		for(int i=0;i<m+1;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(l[j][1]>ry)
					ry=l[j][1];
			}
			cost=l[i][0]+ry;
			if(i==0)min=cost;
			else if(min>cost)
				min=cost;
		}
		cout<<min<<endl;
	}
 } 
