#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int l,m;
	
	while(cin>>l>>m)
	{
		if(l==0&&m==0) break;
		int arr[l+1];
		memset(arr,0,sizeof arr); 
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			for(int i=a;i<=b;i++)
				arr[i]--;
		}
		int cnt = 0;
		for(int i=0;i<=l;i++)
			if(arr[i]==0)
				cnt++;
		cout<<cnt<<endl;
	} 
	
	return 0;
}
