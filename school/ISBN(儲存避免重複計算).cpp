#include <iostream>
#include <vector>
using namespace std;

struct prime	//�s��ƻP�ӽ�ƤG�i��1���ƥ� 
{
	int num;
	int numOf1;
};

int numberOf1(int number)	//��G�i��1���ƥ� 
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
			while(last<=number)		//�[�J�s��� 
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
			for(j=p.size()-1;j>=0;j--)	//���Ƥ��A�P�ؼФG�i��1���ƥجۦP�� 
			{
				if(p[j].num>number) continue;
				if(p[j].numOf1==0)		//�|���p��1�ƥت̡A���i��p�� 
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

