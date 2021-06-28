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
		int count1=0;	//�s�a�I�� 
		int count2[n];	//�s�U�a�I�ʪ�������
		for(int i=0;i<n;i++)
			count2[i]=0; 
			
		string pl[n];			//�s�a�I�W 
		vector<string> ani[n];	//�s�U�a�I�U�U�ʪ��W 
		vector<int> num[n];		//�s�U�a�I�U�U�ʪ��� 
		for(int i=0;i<n;i++)
		{
			cin>>animal;
			cin>>number;
			cin>>place;
		
			int index=exist1(pl,place,count1);	
			if(index!=-1)	//�w�O���Ӧa�W 
			{
				int index2=exist2(ani[index],animal,count2[index]);
				if(index2!=-1)	//�w�b���a�I�O���Ӱʪ��W 
				{
					num[index][index2]+=number;
				}
				else	//���b���a�I�O���Ӱʪ��W
				{
					ani[index].push_back(animal);
					num[index].push_back(number);
					count2[index]++;
				}
			}
			else	//���O���a�W 
			{
				pl[count1]=place;
				ani[count1].push_back(animal);
				num[count1].push_back(number); 
				count2[count1]++;
				count1++;
			}
		}
		for(int i=0;i<count1;i++)	//��X 
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
