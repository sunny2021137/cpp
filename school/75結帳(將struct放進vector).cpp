#include <iostream>
#include <vector>
#include<string>
using namespace std;

struct item	//�s��@�ذӫ~���s���B�����B�ƶq 
{
	int num;
	int price;
	int quantity;
};

void record(vector<item>& v,vector<item>::iterator& it,int number,int price,int quantity)	//�O���Ӷ}�Y�ӫ~�ƶq���B 
{
	for(it=v.begin();it!=v.end();it++)
	{
		if(it->num==number)
		{
			(it->quantity)+=quantity;
			break;
		}
	}
	if(it==v.end())
	{
		item temp;
		temp.num=number;
		temp.price=price;
		temp.quantity=quantity;
		v.push_back(temp);
	}	
}
int main()
{	
	char letter;
	int number,price,quantity,total;
	string str;
	while(cin>>letter)
	{
		total=0; 
		vector<struct item> x,y;
		vector<struct item>::iterator it;
		while(letter!='0')
		{
			cin>>number>>price>>quantity;
			if(letter=='X')
				record(x,it,number,price,quantity);
			else if(letter=='Y')
				record(y,it,number,price,quantity);
			else
				total+=price*quantity;
				
			cin>>letter;
		}		
		for(it=x.begin();it!=x.end();it++)	//��x�}�Y���ӫ~�`�B 
		{ 
			total+=((it->quantity)/2)*(it->price);	
			if((it->quantity)%2==1)total+=(it->price);	
		}
		for(it=y.begin();it!=y.end();it++)	//��y�}�Y���ӫ~�`�B 
		{
			total+=((it->quantity)/2)*(it->price)*1.5;	
			if((it->quantity)%2==1)total+=(it->price);				
		}
	
		cout<<total<<endl;
		cin>>str;	//��Ѿl��0�B�z�� 
	}
		
} 
