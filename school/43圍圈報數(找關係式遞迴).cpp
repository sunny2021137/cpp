#include <iostream>
using namespace std;

int rc(int n,int m,int k)
{
	if(k==0)
		return 0;	//���B����C�������᪺�s���O0 
	else
		return (rc(n-1,m,k-1)+m)%n; //n�H�Pn-1�H���s�����Y 
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
