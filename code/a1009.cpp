#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int k;
    double arr[2010] = {0};
    cin>>k;
    while(k--)
    {
        int a;double b;
        cin>>a>>b;
        arr[a]+=b;
    }
    cin>>k;

    double res[2010] = {0};

    while(k--)
    {
        int a;double b;
        cin>>a>>b;

        for(int i=2001;i>=0;i--)
        {
            if(arr[i]!=0)
            {
                int k = a+i;
                res[k]+=arr[i]*b;
            }
        }
    }
    int cnt = 0;
    for(int i=2001;i>=0;i--)
        if(res[i])
            cnt++;
    cout<<cnt;
    
    for(int i=2001;i>=0;i--)
    {
        if(res[i])
            printf(" %d %.1f",i,res[i]);
    }
    
    return 0;
}
