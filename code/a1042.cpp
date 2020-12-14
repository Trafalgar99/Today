#include<iostream>
#include<vector>
#include<algorithm>
#include<string >

using namespace std;

int main()
{
	
	vector<string> v;
	vector<string> vv(54);
	v.push_back("null");
	for(int i=1;i<=13;i++)
		v.push_back("S"+to_string(i));	
	for(int i=1;i<=13;i++)
		v.push_back("H"+to_string(i));
	for(int i=1;i<=13;i++)
		v.push_back("C"+to_string(i));
	for(int i=1;i<=13;i++)
		v.push_back("D"+to_string(i));
	v.push_back("J1");
	v.push_back("J2");
	
	int n;
	cin>>n;
	vector<int> v2;
	v2.push_back(0);
	for(int i=1;i<=54;i++)
	{
		int x;
		cin>>x;
		v2.push_back(x);
	}
	
	while(n--)
	{
		for(int i=1;i<=54;i++)
		{
			vv[v2[i]] = v[i];
		}
		for(int i=1;i<=54;i++)
			v[i] = vv[i];
	}
	for(int i=1;i<=54;i++)
		cout<<vv[i]<<' ';
	return 0;	
} 

