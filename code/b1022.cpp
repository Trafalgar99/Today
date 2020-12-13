#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int a,b,d;
	cin>>a>>b>>d;
	a = a+b;
	vector<int> v;
	do
	{		//  --------------Ð´Ò»Æª²©¿Í 
			v.push_back(a%d);
			a /= d;
	}while(a);
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i];
	}
	
	return 0;
} 
