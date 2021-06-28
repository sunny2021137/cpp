#include<iostream>
#include<algorithm>

using namespace std; 
bool check(int *p,int d,int n,int k);
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int p[n],d[k],max,min=1,mid;
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
		}
		sort(p,p+n);
		max=p[n-1]-p[0];
		while(max!=min)
		{
			mid=(max+min)/2;
			if(check(p,mid,n,k))
				max=mid;
			else
				min=mid+1;
		}
		cout<<min<<endl;	
	}
}
bool check(int *p,int d,int n,int k)
{
	int index=0;
	for(int i=0;i<k;i++)
	{
		int j;
		for(j=index;j<n;j++)
		{
			if(p[j]-p[index]>d)
			{
				index=j;
				break;
			}
		}
		if(j==n)
		{
			index=n;
			break; 
		} 
	}
	if(index<=n-1)return false;
	else return true;
}
