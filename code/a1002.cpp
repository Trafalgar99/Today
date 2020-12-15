#include<iostream>


using namespace std;

int main()
{
//     cout<<"asdfsda"<<endl;
    int k1;
    int cnt = 0;
    cin>>k1;

    double arr[1010] = {0};
    while(k1--)
    {
        int a;
        double b;
        cin>>a>>b; // !
        arr[a] = b;
    }
    int k2;
    cin>>k2;

    while(k2--)
    {
        int a;double b;
        cin>>a>>b;
        double m = arr[a];
        arr[a]+=b;

    }
    for(int i=1001;i>=0;i--)
    {
        if(arr[i]!=0) cnt++;
    }
    cout<<cnt;
    for(int i=1001;i>=0;i--)
    {
        if(arr[i]!=0)
        {
            printf(" %d %.1f",i,arr[i]);
        }
    }
    return 0;
}
