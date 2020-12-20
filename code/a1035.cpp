#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<char,char>m;
    m['1'] = '@';
    m['0'] = '%';
    m['l'] = 'L';
    m['O'] = 'o';
    vector<pair<string,string>> res;
    int n;
    cin>>n;
    int cnt = 0;
    string user,pwd;
    for(int i=0;i<n;i++)
    {
        cin>>user>>pwd;
        int flag = 0;
        for(int i=0;i<pwd.size();i++)
        {
            if(pwd[i]=='l'||pwd[i]=='0'||pwd[i]=='O'||pwd[i]=='1')
            {
                pwd[i] = m[pwd[i]];
                flag = 1;
            }
        }
        if(flag==1)
            res.push_back({user,pwd});
        cnt+=flag;
    }
    if(cnt==0)
    {
        if(n==1)
            cout<<"There is 1 account and no account is modified"<<endl;
        else
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    else
    {
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
            cout<<res[i].first<<' '<<res[i].second<<endl;
    }
    
    return 0;
}
