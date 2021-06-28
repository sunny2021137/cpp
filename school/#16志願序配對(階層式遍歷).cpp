#include<iostream>

using namespace std;


int main()
{

		
		int a[10][11],b[10][11],ans[10],temp[10];
		char t;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<11;j++)
			{
				cin>>t>>a[i][j];
			}
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<11;j++)
			{
				cin>>t>>b[i][j];
			}
		}
		int num=10;
		for(int h=1;h<=10;h++)
		{
			if(num==0)break;
			for(int i=0;i<10;i++)
			{
				int count=0,index;
				if(b[a[i][h]-1][0]==0)
					continue;
				if(a[i][0]==0)
					continue;
				index=a[i][h];
				for(int j=i;j<10;j++)
				{
					if(a[j][h]==index && a[j][0]!=0)
					{
						temp[count]=a[j][0];
						count++;
					}
			 }
				if(count==1)
				{
					ans[temp[0]-1]=index;
					a[temp[0]-1][0]=0;
					b[index-1][0]=0;
					num--;
				}
				else
				{
					for(int i=1;i<=10;i++)
					{
						int j;
						for(j=0;j<count;j++)
						{
							if(b[index-1][i]==temp[j])
							{
								ans[temp[j]-1]=index;
								a[temp[j]-1][0]=0;
								b[index-1][0]=0;
								num--;
								break;
							}
						}
						if(j<count)
							break;
				 }
				}
				for(int i=0;i<count;i++)
					temp[i]=0;
			}
		}
		for(int i=0;i<10;i++)
		{
			cout<<"A"<<i+1<<",B"<<ans[i]<<endl;
		}
	
 } 
