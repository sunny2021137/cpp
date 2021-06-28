#include <iostream>
using namespace std;

int rc(int n,int m,int k)
{
	if(k==0)
		return 0;	//幸運兒圍圈遊戲結束後的編號是0 
	else
		return (rc(n-1,m,k-1)+m)%n; //n人與n-1人的編號關係 
}
int main()
{
	int n,m,k;
	while(cin>>n)
	{
		cin>>m;
		cin>>k;	
		cout<<rc(n,m,k)+1<<endl;
	}
}
