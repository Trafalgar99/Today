#include<iostream>

using namespace std;

const int N = 1e5+10;

int arr[N];

int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		int a,b;
		cin>>a>>b;
		arr[a]+=b;
	}
	int maxi=0,maxd=arr[0];
	for(int i=0;i<N;i++)
	{
		if(arr[i]>arr[maxi])
		{
			maxi = i;
			maxd = arr[i];
		}
	}
	cout<<maxi<<' '<<maxd<<endl;
	
	return 0;
}
