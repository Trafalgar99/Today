#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;char c;
    cin>>n>>c;
    
    int x = floor(sqrt(2.0*(1+n)))-1;
    if(x%2==0) x-=1;

    int spare = (1+x)*(1+x)/2-1;
    
    for(int i = x; i>=1; i-=2)
    {
        for(int j=0;j<(x-i)/2;j++)
            cout<<' ';
        for(int k = 0;k<i;k++)
            cout<<c;
        cout<<endl;
    }
    for(int i = 3; i<=x; i+=2)
    {
        for(int j=0;j<(x-i)/2;j++)
            cout<<' ';
        for(int k = 0;k<i;k++)
            cout<<c;
        cout<<endl;
    }
    cout<<n-spare<<endl;
    return 0;
}
