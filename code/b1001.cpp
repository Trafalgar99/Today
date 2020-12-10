#include<iostream>

using namespace std;

int main()
{
	int cnt = 0;
	int n;
	cin>>n;
	while(n!=1)
	{
		cnt++;
		if(n%2 == 0)
			n = n/2;
		else
			n = (3*n+1)/2;
	}
	cout<<cnt<<endl;
	
	return 0;
 } 
