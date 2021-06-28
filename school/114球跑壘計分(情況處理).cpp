#include <iostream>
using namespace std;

int base[3];
int out,score;

void B(int i)
{
	if(i!=4)	//非HR的安打 
	{
		for(int k=0;k<i;k++)
			if(base[2-k]==1) score++;	//i壘打得分=後i壘上人數 
	}
	else
	{
		for(int k=0;k<3;k++)
			if(base[k]==1) score++;
		score++;	//全壘打分數=壘上人數+1打者 
	}

	for(int k=2;k>=i;k--) //比i還大的壘包繼承前i個壘包 
		base[k]=base[k-i];
	if(i!=4) base[i-1]=1;	//打者上到第i壘 
	for(int k=0;k<i-1;k++)	//小於i的壘包無人 
		base[k]=0;
}
int main()
{
	int times,b;
	while(cin>>times)
	{
		string play[9][5];
		out=0,score=0;
		
		for(int i=0;i<3;i++)	//初始化 
			base[i]=0;
		for(int i=0;i<9;i++)
			for(int j=0;j<5;j++)
				play[i][j]="stop";
				
		for(int i=0;i<times;i++)
			cin>>play[0][i];
			
		for(int i=1;i<9;i++)
		{
			cin>>times;
			for(int j=0;j<times;j++)
				cin>>play[i][j];
		}
		cin>>b;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(play[j][i]=="1B") B(1);
				else if(play[j][i]=="2B") B(2);
				else if(play[j][i]=="3B") B(3);
				else if(play[j][i]=="HR") B(4);
				else if(play[j][i]=="stop") break;
				else
				{
					out++;
					if(out==b) break;
					if(out%3==0)
					{
						base[0]=0;
						base[1]=0;
						base[2]=0;
					}
				}
			}
			if(out==b)break;
		}
		cout<<score<<endl;
	}
}
