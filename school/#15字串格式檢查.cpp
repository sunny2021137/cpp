#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string> part;
vector<string>::iterator iter;
vector<int> type;
vector<int>::iterator iteri;
int num0=0,num1=0,q0,q1;
bool find(string a,int c0,int c1,int r)
{
	while(1) 
	{
		string temp="";
		int n=*iteri;
		if(n==0)
		{
			num0++;
			for(int i=0;i<c0;i++)
			{
				temp+=*iter;
			}
			int j;
			for(j=0;j<temp.size();j++)
			{
				if(temp[j]!=a[j])
					break;
			}
			if(j!=temp.size())
			{
				num0--;
				iter--;
				iteri--;
				return 0;
			}
			else
			{
				iteri++;
				if(iteri==type.end())
				{
					if(temp.size()==a.size())
					{
						q0=c0;
						q1=c1;
						return 1;
					}
					else
					{
						num0--;
						iter--;
						iteri--;
						iteri--;
						return 0;
					}
				}
				iter++;
				if(find(&a[temp.size()],c0,c1,r)==0)
				{
					if(num0==1)
					{
						c0++;
						if(r==0)c1=1;
						num0--;
						continue;
					}
					else
					{
						num0--;
						iter--;
						iteri--;
						return 0;
					}
				}
				else
				{
					return 1;
				}
			}
		}
		else
		{
			num1++;
			for(int i=0;i<c1;i++)
			{
				temp+=*iter;
			}
			int j;
			for(j=0;j<temp.size();j++)
			{
				if(temp[j]!=a[j])
					break;
			}
			if(j!=temp.size())
			{
				num1--;
				iter--;
				iteri--;
				return 0;
			}
			else
			{
				
				iteri++;
				if(iteri==type.end())
				{
					if(temp.size()==a.size())
					{
						q0=c0;
						q1=c1;
						return 1;
					}
					else
					{
						num1--;
						iter--;
						iteri--;
						iteri--;
						return 0;
					}
				}
				iter++;
				if(find(&a[temp.size()],c0,c1,r)==0)
				{
					if(num1==1)
					{
						c1++;
						if(r==1)c0=0;
						num1--;
						continue;
					}
					else
					{
						num1--;
						iter--;
						iteri--;
						return 0;
					}
				}
				else
				{
					return 1;
				}
			}
		}
	}
}
int main()
{
	string input;
	while(cin>>input)
	{
		part.clear();
		type.clear();
		string temp="";
		for(int i=0;i<input.size();i++)
		{
			
			if(input[i]=='n')
			{
				if(input[i-1]!=')')
				{
					temp+=input[i-1];
					part.push_back(temp);
					type.push_back(1);
					temp="";
				}
			}
			else if(input[i]=='*')
			{
				if(input[i-1]!=')')
				{
					temp+=input[i-1];
					part.push_back(temp);
					type.push_back(0);
					temp="";
				}
			}
			if(input[i]=='(')
			{
				int j=0;
				for(j;j<input.size();j++)
				{
					if(input[i+j+1]==')')
						break;
					temp+=input[i+j+1];
				}
				if(input[i+j+2]=='*')
				{
					part.push_back(temp);
					type.push_back(0);
					temp="";
				}
				if(input[i+j+2]=='n')
				{
					part.push_back(temp);
					type.push_back(1);
					temp="";
				}
				
			}
		}
		int n;
		cin>>n;
		string a;
		for(int i=0;i<n;i++)
		{
			int r;
			num0=0;
			num1=0;
			cin>>a;
			iter=part.begin();
			iteri=type.begin();
			if(*iteri==1)
				r=1;
			else 
				r=0;
			if(find(a,0,1,r)==0)
				cout<<"N"<<endl;
			else
			{
				cout<<"Y "<<q1<<" "<<q0<<endl;
			}
			
		}
	}
 } 
