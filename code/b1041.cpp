#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<string,int>> v(1001);

    while(n--)
    {
        string s;int a,b;
        cin>>s>>a>>b;
        v[a] = {s,b};
    }
    int k;
    cin>>k;

    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        cout<<v[x].first<<' '<<v[x].second<<endl;
    }
    
    return 0;
}
