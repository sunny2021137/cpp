#include <iostream>

using namespace std;

const int co[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}}; 	//四方向 
struct sum	//存x和y總和 
{
	int x;
	int y;
};
struct sum rc(int a,int b,int d,int x)
{
	sum total;	//用來存到此層累積總和 
	if(a>0&&b>0)	//此層 
	{
		total.x=a;
		total.y=b;
	}
	else
	{
		total.x=0;
		total.y=0;
	}
	
	if(x<0)
		return total;
	else	//x>=0,加入上層總和 
	{
		for(int i=0;i<4;i++)	//四方向 
		{
			sum son=rc(a+(d/2)*co[i][0],b+(d/2)*co[i][1],d/2,x-1);
			total.x+=son.x;
			total.y+=son.y;				
		}
		return total;
	}
	
}
int main()
{
	int a,b,d,x;
	while(cin>>a)
	{
		cin>>b>>d>>x;
		sum total=rc(a,b,d,x);
		cout<<total.x<<" "<<total.y<<endl;
	}
}
