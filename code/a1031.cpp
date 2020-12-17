#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int N = s.size();
    // find n1,2,3
    int n1,n2,n3;
    for(n2=0;n2<=N;n2++)
    {
        if((N-n2+2)%2 == 0)
        {
            n1 = n3 = (N-n2+2)/2;
            if(n1<=n2) break;
        }
    }
//     cout<<n1<<' '<<n2<<' '<<n3<<endl;
    for(int i=0;i<n1-1;i++)
    {
//         cout<<s[i]<<string(" ",n2-2)<<s[N-1-i]<<endl;
        cout<<s[i];
        for(int j = 0;j<n2-2;j++)
            cout<<' ';
        cout<<s[N-1-i]<<endl;
    }
    
        for(int i = n1-1;i<n1+n2-1;i++)
        cout<<s[i];
    
    
    return 0;
}
