#include <iostream>
using namespace std;

int base[3];
int out,score;

void B(int i)
{
	if(i!=4)	//�DHR���w�� 
	{
		for(int k=0;k<i;k++)
			if(base[2-k]==1) score++;	//i�S���o��=��i�S�W�H�� 
	}
	else
	{
		for(int k=0;k<3;k++)
			if(base[k]==1) score++;
		score++;	//���S������=�S�W�H��+1���� 
	}

	for(int k=2;k>=i;k--) //��i�٤j���S�]�~�ӫei���S�] 
		base[k]=base[k-i];
	if(i!=4) base[i-1]=1;	//���̤W���i�S 
	for(int k=0;k<i-1;k++)	//�p��i���S�]�L�H 
		base[k]=0;
}
int main()
{
	int times,b;
	while(cin>>times)
	{
		string play[9][5];
		out=0,score=0;
		
		for(int i=0;i<3;i++)	//��l�� 
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
