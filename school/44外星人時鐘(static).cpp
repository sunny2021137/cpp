#include <iostream>
using namespace std;

int *translate(char planet,int h,int m,int s)
{
	static int newclock[3];	//記得設成static!!! 
	int h1,m1,h2,m2;
	if(planet=='Z')
	{
		cout<<"E ";
		h1=48;
		m1=30;
		h2=60;
		m2=60;
	}
	else if(planet=='E')
	{
		cout<<"Z ";
		h1=60;
		m1=60;
		h2=48;
		m2=30;
	}
	int second=(h*h1+m)*m1+s;	//全換成秒 
	
	newclock[0]=second/(h2*m2);	//轉換中 
	second=second%(h2*m2);
	newclock[1]=second/m2;
	newclock[2]=second%m2;
	return newclock;
}
int main()
{
	int n;
	while(cin>>n)
	{
		char planet;
		int h,m,s;
		for(int i=0;i<n;i++)
		{
			cin>>planet;
			cin>>h>>m>>s;
			int *newclock=translate(planet,h,m,s);
			cout<<*newclock+0<<" "<<*(newclock+1)<<" "<<*(newclock+2)<<endl;	//記得加括號!!!	
		}
	}
} 
