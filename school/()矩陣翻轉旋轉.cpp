#include <iostream>
using namespace std;

int R,C;
void s(int a,int **m1,int **m2,int r,int c) 
{
	if(a==0)
	{
		R=c;
		C=r;
	}
	else
	{
		R=r;
		C=c;
	}
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			*(*(m1+(C-1-j))+i)=*(*(m2+i)+j);
		}
	}
}
void f(int **m,int r,int c)
{
	int temp;
	for(int i=0;i<r/2;i++)
	{
		for(int j=0;j<c;j++)
		{
			temp=*(*(m+i)+j);
			*(*(m+i)+j)=*(*(m+(r-1-i))+j);
			*(*(m+(r-1-i))+j)=temp;
		}
	}
}
int main()
{
	int r,c,n,act;
	while(cin>>r>>c>>n)
	{
		int x[r][c],y[c][r];
		int (*a)[c]=x,(*b)[r]=y;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>*(*(a+i)+j);
		int count=0;
		for(int i=0;i<n;i++)
		{
			cin>>act;
			int temp;
			if(act==0)
			{
				if(count%2==0) s(0,(int**)b,(int**)a,r,c);
				else s(1,(int**)a,(int**)b,r,c);
				count++;
			}
			else
			{
				if(count%2==0) f((int**)a,r,c);
				else f((int**)b,c,r);
			}
		}
		if(count%2==0)
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<*(*(a+i)+j);;
					if(j==c-1) cout<<endl;
					else cout<<" ";
				}			
			}
		}
		else
		{
			for(int i=0;i<c;i++)
			{
				for(int j=0;j<r;j++)
				{
					cout<<*(*(b+i)+j);
					if(j==r-1)cout<<endl;
					else cout<<" ";
				}			
			}
		}
	}
}

