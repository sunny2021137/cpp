#include<iostream>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		long long int sum=0,total=0;
		int w[n],f[n];
		for(int i=0;i<n;i++)
		{
			cin>>w[i];
			total+=w[i];
		}
		for(int j=0;j<n;j++)
			cin>>f[j];
		for(int i=0;i<n;i++)
		{
			int index,temp;
			for(int j=0;j<n-1;j++)
			{
				if(w[j+1]*f[j]<w[j]*f[j+1])          //(1)w1,w2,w3.......wi,wi+1.......wn
				{                                    //(2)w1,w2,w3.......wi+1,wi.......wn
					temp=w[j+1];                     //A=w1+w2+w3....+wi-1
					w[j+1]=w[j];                     //->(1)A*fi+(A+wi)*fi+1
					w[j]=temp;                       //->(2)A*fi+1 +(A+wi+1)*fi
					temp=f[j+1];                     //-->if((2)<(1))wi,wi+1­n¥æ´« 
					f[j+1]=f[j];                     // A*fi+1 +(A+ wi+1 )*fi <A*fi+(A+wi)*fi+1 ==> wi+1 * fi < wi *fi+1
					f[j]=temp;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			total-=w[n-i-1];
			sum+=total*f[n-i-1];
		}
	cout<<sum<<endl;	
	}
 } 
