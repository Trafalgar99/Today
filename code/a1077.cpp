#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    getchar(); // cin 会留下缓冲区的换行符
    string s[n];
    int min = 9999;
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);
        if(s[i].size()<min)
            min = s[i].size();
        reverse(s[i].begin(),s[i].end());
    }
    
//     for(int i=0;i<n;i++)
//         cout<<s[i]<<endl;
    int len = 0;
    for(int i=0;i<min;i++)
    {   
        bool ok = true;
        for(int j=0;j<n;j++)
        {
            if(s[j][i]!=s[0][i])
            {
                ok = false;
                break;
            }
        }
        if(ok == true)
        {
            len++;
        }
        else
            break;
    }
    if(len == 0)
        cout<<"nai"<<endl;
    else{
        string res;
        for(int i=0;i<len;i++)
            res+=s[0][i];

        reverse(res.begin(),res.end());

        cout<<res<<endl;
        return 0;        
    }

}
