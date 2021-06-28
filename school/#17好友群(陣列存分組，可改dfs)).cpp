#include<iostream>

using namespace std;

int main()
{
	long int all,mate;
	while(cin>>all>>mate)
	{
		int c=0,s=0,t=0,p[all],a,b;
		for(int i=0;i<all;i++)
		{
			p[i]=0;
		}
		for(int i=0;i<mate;i++)
		{
			cin>>a>>b;
			if(i==0)
			{
				if(a==b)
				{
					s++;
				}
				else 
				{
					s+=2;	
				}
				c++;
				t++;
				p[a]=t;
				p[b]=t;
			}
			else
			{
				if(p[a]!=0 && p[b]==0)
				{
					s++;
					p[b]=p[a];
				}
				else if(p[a]==0 && p[b]!=0)
				{
					p[a]=p[b];
					s++;
				}
				else if(p[a]==0 && p[b]==0)
				{
					if(a==b)
					{
						s++;
					}
					else 
					{
						s+=2;
					}
					c++;
					t++;
					p[a]=t;
					p[b]=t;
				}
				else 
				{
					if(p[a]!=p[b])
					{
						c--;
						int temp=p[b],tt=p[a];
						for(int k=0;k<all;k++)
						{
							if(p[k]==temp)
								p[k]=tt;
						}
					}
				}
			}
		}
		c=c+all-s;
		cout<<c<<endl;
	}
 } 
