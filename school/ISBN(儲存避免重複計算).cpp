#include <iostream>
#include <vector>
using namespace std;

struct prime	//存質數與該質數二進位1的數目 
{
	int num;
	int numOf1;
};

int numberOf1(int number)	//算二進位1的數目 
{
	int count=0;
	while(1)
	{
		if(number%2==1)count++;
		if(number==0)break;
		number/=2;
	}
	return count;
}
int main()
{
	int number,last=2;
	vector<prime> p;
	while(cin>>number)
	{
		while(number!=0)
		{
			int input_1=numberOf1(number),i,j;
			while(last<=number)		//加入新質數 
			{
				for(i=2;i<last;i++)
					if(last%i==0)break;
				if(i>=last)
				{
					prime newPrime;
					newPrime.num=last;
					newPrime.numOf1=0;
					p.push_back(newPrime); 
				}
				last++;
			}
			for(j=p.size()-1;j>=0;j--)	//找質數中，與目標二進位1的數目相同者 
			{
				if(p[j].num>number) continue;
				if(p[j].numOf1==0)		//尚未計算1數目者，先進行計算 
					p[j].numOf1=numberOf1(p[j].num);
				if(input_1==p[j].numOf1)
				{
					cout<<p[j].num<<endl;
					break;
				}
			}
			if(j<0)	cout<<0<<endl;
			cin>>number;
		}
	}
}

