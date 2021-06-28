#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int exist1(string pl[],string place,int count1) 
{
	for(int i=0;i<count1;i++)
		if(pl[i]==place) return i; 
		
	return -1;
}
int exist2(vector<string> ani,string animal,int count2)
{
	for(int i=0;i<count2;i++)
		if(ani[i]==animal) return i; 

	return -1;
}

int main()
{
	int n;
	string animal,place;
	int number;
	while(cin>>n)
	{
		int count1=0;	//存地點數 
		int count2[n];	//存各地點動物種類數
		for(int i=0;i<n;i++)
			count2[i]=0; 
			
		string pl[n];			//存地點名 
		vector<string> ani[n];	//存各地點下各動物名 
		vector<int> num[n];		//存各地點下各動物數 
		for(int i=0;i<n;i++)
		{
			cin>>animal;
			cin>>number;
			cin>>place;
		
			int index=exist1(pl,place,count1);	
			if(index!=-1)	//已記錄該地名 
			{
				int index2=exist2(ani[index],animal,count2[index]);
				if(index2!=-1)	//已在此地點記錄該動物名 
				{
					num[index][index2]+=number;
				}
				else	//未在此地點記錄該動物名
				{
					ani[index].push_back(animal);
					num[index].push_back(number);
					count2[index]++;
				}
			}
			else	//未記錄地名 
			{
				pl[count1]=place;
				ani[count1].push_back(animal);
				num[count1].push_back(number); 
				count2[count1]++;
				count1++;
			}
		}
		for(int i=0;i<count1;i++)	//輸出 
		{
			cout<<pl[i]<<" : ";
			for(int j=0;j<count2[i];j++)
			{
				cout<<ani[i][j]<<" "<<num[i][j];
				if(j!=count2[i]-1)
					cout<<", ";
			}
			cout<<endl;
		}
	}
	
} 
