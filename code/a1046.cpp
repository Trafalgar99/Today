#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    v.push_back(0);
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x+sum); //v[i] -> i+1 -- 1 distance   m -- n --> 
        sum+=x;
    }
    int k;
    cin>>k;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            int c = a;
            a = b;
            b = c;
        }
        int path = 0;
        path = v[b-1]-v[a-1];
        path = min(path,sum-path);
        
        cout<<path<<endl;
    }
    
    
    return 0;
}
