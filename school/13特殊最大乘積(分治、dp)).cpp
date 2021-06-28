#include<iostream>

using namespace std;
int findmax(int *a,int i,int j)
{
	int temp,max;
	int v[j][j];
	
	for(int g=1;g<=j-i;g++)
		for(int s=i;s<=j-g;s++)
		{
			if(g<2)v[s][s+g]=0;
			else
			{
				for(int x=s+1;x<s+g;x++)
				{
					if(x==s+1)
					{
						max=v[s][x]+v[x][s+g]+a[s]*a[x]*a[s+g];
					}
					else
					{
						temp=v[s][x]+v[x][s+g]+a[s]*a[x]*a[s+g];
						if(temp>max)max=temp;
					}
				}
				v[s][s+g]=max;
			}
		}
	return v[i][j];
}

int findmin(int *a,int i,int j)
{
	int temp,min;
	int v[j][j];
	
	for(int g=1;g<=j-i;g++)
		for(int s=i;s<=j-g;s++)
		{
			if(g<2)v[s][s+g]=0;
			else
			{
				for(int x=s+1;x<s+g;x++)
				{
					if(x==s+1)
					{
						min=v[s][x]+v[x][s+g]+a[s]*a[x]*a[s+g];
					}
					else
					{
						temp=v[s][x]+v[x][s+g]+a[s]*a[x]*a[s+g];
						if(temp<min)min=temp;
					}
				}
				v[s][s+g]=min;
			}
		}
	return v[i][j];
}
int main()
{
	int n;
	while(cin>>n)
	{
		int length[n],num[n][100];
		int max[n],min[n];
		for(int i=0;i<n;i++)
		{
			cin>>length[i];
			for(int j=0;j<length[i];j++)
				cin>>num[i][j];
		}
		for(int i=0;i<n;i++)
		{
			max[i]=findmax(num[i],0,length[i]-1);
			min[i]=findmin(num[i],0,length[i]-1);
		}
		for(int j=0;j<n;j++)
			cout<<max[j]<<" "<<min[j]<<endl;
	}
 } 
