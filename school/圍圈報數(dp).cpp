#include <iostream>
using namespace std;

int main()
{
	int n,m,k;
	while(cin>>n)
	{
		cin>>m;
		cin>>k;
		int dp=0;
		int people=n-k+1;
		//�ϥ�for�j����N���j 
		for(int i=0;i<k;i++)
		{
			dp=(dp+m)%people;
			cout<<dp<<endl;
			people++;
		} 
		cout<<dp+1<<endl;
	}
}
