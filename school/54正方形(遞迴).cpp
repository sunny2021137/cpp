#include <iostream>

using namespace std;

const int co[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}}; 	//�|��V 
struct sum	//�sx�My�`�M 
{
	int x;
	int y;
};
struct sum rc(int a,int b,int d,int x)
{
	sum total;	//�ΨӦs�즹�h�ֿn�`�M 
	if(a>0&&b>0)	//���h 
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
	else	//x>=0,�[�J�W�h�`�M 
	{
		for(int i=0;i<4;i++)	//�|��V 
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
