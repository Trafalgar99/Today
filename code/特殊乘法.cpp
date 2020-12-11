#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
//		cout<<s1<<endl<<s2<<endl;
		int res = 0;
		for(int i=0;i<s1.size();i++)
			for(int j=0;j<s2.size();j++)
			{
				res += (s1[i]-'0')*(s2[j]-'0');
			}
		cout<<res<<endl;
	}
	
	return 0;
} 
