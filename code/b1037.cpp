#include<iostream>

using namespace std;

int main()
{
    int a1,b1,c1,a2,b2,c2;
    scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
    int k1 = a1*17*29+b1*29+c1;
    int k2 = a2*17*29+b2*29+c2;
    
    long long res = k2-k1;
    
    if(res>0)
    {
        cout<<res/(29*17)<<'.'<<res/29%17<<'.'<<res%29<<endl;
    }
    else if(res<0)
    {
        res = -res;
        cout<<'-'<<res/(29*17)<<'.'<<res/29%17<<'.'<<res%29<<endl;
    }
    else
    {
        cout<<"0.0.0"<<endl;
    }
    return 0;
}
