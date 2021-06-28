#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,temp,change=1,max,count,c,page;
	while(cin>>n)
	{
		vector<int> score;
		cin.get();
		for(int i=0;i<n;i++)
		{
			count=0,max=-1,page=0;
			while(1)	//ぃ﹚块 
			{
				cin>>temp;
				if(temp>max)max=temp;
				score.push_back(temp);
				count++;
				c=cin.get();
				if(c=='\n'||c=='\r')break;
			}
		
			if(max<=95)	//程ぃ禬筁95秈︽秸だ 
			{
				int add=95-max;
				for(int j=0;j<count;j++)
					if(score[j]+add<=59&&score[j]+add>=55)page++;	//参璸干σ计 
			}
			score.clear();
			cout<<page<<endl;
		}
	}
}
