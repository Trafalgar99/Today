#include<iostream>

using namespace std;

int main()
{
    int k;
    while(cin>>k)
    {
        int odd=0,even=0;
        while(k--)
        {
            int x;
            cin>>x;
            if(x%2)
                odd++;
            else even++;
        }
        if(odd>=even)puts("YES");
        else puts("NO");
    }
    
    return 0;
}
