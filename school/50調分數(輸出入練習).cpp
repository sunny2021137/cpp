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
			while(1)	//不定長輸入 
			{
				cin>>temp;
				if(temp>max)max=temp;
				score.push_back(temp);
				count++;
				c=cin.get();
				if(c=='\n'||c=='\r')break;
			}
		
			if(max<=95)	//最大值不超過95，進行調分 
			{
				int add=95-max;
				for(int j=0;j<count;j++)
					if(score[j]+add<=59&&score[j]+add>=55)page++;	//統計補考人數 
			}
			score.clear();
			cout<<page<<endl;
		}
	}
}
