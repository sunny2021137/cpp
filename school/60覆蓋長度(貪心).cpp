#include <iostream>

using namespace std;

void mysort(int c[][2],int n)	//bubble sort�̶}�Y�Ѥp��j�� 
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(c[j][0]>c[j+1][0])
			{
				int temp=c[j][0];
				c[j][0]=c[j+1][0];
				c[j+1][0]=temp;
				
				temp=c[j][1];
				c[j][1]=c[j+1][1];
				c[j+1][1]=temp;
			}
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		int length=0;
		int co[n][2];
		for(int i=0;i<n;i++)
		{
			cin>>co[i][0];
			cin>>co[i][1];
		}
		mysort(co,n);	//�Ƨ� 
		int first=co[0][0],last=co[0][1];
		for(int i=0;i<n;i++)
		{
			if(i==n-1) length+=last-first;
			else if(last>co[i+1][0])
			{
				if(co[i+1][1]>last)last=co[i+1][1];	//�վ�̧� 
			} 
			else
			{
				length+=last-first;	//�p��s��u�q�� 
				first=co[i+1][0];	//���s�]�w�Y�� 
				last=co[i+1][1];
			}
		}
		cout<<length;
	}
} 
