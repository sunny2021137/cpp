#include<iostream>
#include<string>

using namespace std;
struct found
{
	int max;
	int min;
};

int main()
{
	string s1,s2;
	int cost;
	while(cin>>s1>>s2>>cost)
	{
		int n=s1.size(),m=s2.size();
		found f[n+1][m+1];
		int len=n-m,temp,t1,t2;
		for(int i=0;i<=n;i++)
		{
			int j=0;
			if(i-len>0) j=i-len;
			for(j;j<=m;j++)
			{
				if(i==0)
				{
					f[i][j].min=0;
					f[i][j].max=0;
				}
				else if(i==1)
				{
					if(j<1)
					{
						temp=cost-s1[0]+'A'-1;
						if(temp<0)
							temp*=-1;
						f[i][j].min=temp;
						f[i][j].max=temp;
					}
					else if(j==1)
					{
						temp=s1[0]-s2[0];
						if(temp<0)
							temp*=-1;
						f[i][j].min=temp;
						f[i][j].max=temp;
					}
					else if(j>1)
					{
						f[i][j].min=0;
						f[i][j].max=0;
					}
				}
				else
				{
					if(i>j)
					{
						if(j==0)
						{
							temp=cost-s1[i-1]+'A'-1;
							if(temp<0) temp*=-1;
							f[i][j].min=f[i-1][j].min+temp;
							f[i][j].max=f[i-1][j].max+temp;
						}
						else
						{
							t1=cost-s1[i-1]+'A'-1;
							if(t1<0) t1*=-1;
							t2=s1[i-1]-s2[j-1];
							if(t2<0) t2*=-1;
							if(f[i-1][j].min+t1<f[i-1][j-1].min+t2)
								f[i][j].min=f[i-1][j].min+t1;
							else
								f[i][j].min=f[i-1][j-1].min+t2;
							if(f[i-1][j].max+t1>f[i-1][j-1].max+t2)
								f[i][j].max=f[i-1][j].max+t1;						
							else
								f[i][j].max=f[i-1][j-1].max+t2;
						}
					}
					else if(i==j)
					{
						temp=s1[i-1]-s2[j-1];
						if(temp<0) temp*=-1;
						temp+=f[i-1][j-1].max;
						f[i][j].min=temp;
						f[i][j].max=temp;
					}
					else
					{
						f[i][j].min=0;
						f[i][j].max=0;
					}
				}
			}
		}
		cout<<f[n][m].min<<" "<<f[n][m].max<<endl;
	}
 } 
