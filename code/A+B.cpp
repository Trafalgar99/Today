#include<iostream>
#include<string>

using namespace std;

int main()
{
	string input1,input2;
	while(cin>>input1>>input2)
	{
//		cout<<input<<"kxkxkx"<<endl;
//		int x = input.find(' ');
		int a=0,b=0;
		for(int i=0;i<input1.size();i++)
		{
			if(input1[i]>='0'&&input1[i]<='9')
			{
				a*=10;
				a+=input1[i]-'0';
			}
		}
		if(input1[0]=='-')
			a*=-1;
		for(int i=0;i<input2.size();i++)
		{
			if(input2[i]>='0'&&input2[i]<='9')
			{
				b*=10;
				b+=input2[i]-'0';
			}			
		}
		if(input2[0]=='-')
			b*=-1;
		cout<<a+b<<endl;
	}
	return 0;
} 
